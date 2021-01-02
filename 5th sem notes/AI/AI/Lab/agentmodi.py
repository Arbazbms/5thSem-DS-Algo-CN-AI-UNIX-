import utils 
import random, copy
class Thing(object):
    """This represents any physical object that can appear in an Environment.
    You subclass Thing to get the things you want.  Each thing can have a
    .__name__  slot (used for output only)."""
    def __repr__(self):
        return '<%s>' % getattr(self, '__name__', self.__class__.__name__)

    def is_alive(self):
        "Things that are 'alive' should return true."
        return hasattr(self, 'alive') and self.alive

    def show_state(self):
        "Display the agent's internal state.  Subclasses should override."
        print "I don't know how to show_state."

    def display(self, canvas, x, y, width, height):
        # Do we need this?
        "Display an image of this Thing on the canvas."
        pass

class Agent(Thing):
    """An Agent is a subclass of Thing with one required slot,
    .program, which should hold a function that takes one argument, the
    percept, and returns an action. (What counts as a percept or action
    will depend on the specific environment in which the agent exists.)
    Note that 'program' is a slot, not a method.  If it were a method,
    then the program could 'cheat' and look at aspects of the agent.
    It's not supposed to do that: the program can only look at the
    percepts.  An agent program that needs a model of the world (and of
    the agent itself) will have to build and maintain its own model.
    There is an optional slot, .performance, which is a number giving
    the performance measure of the agent in its environment."""

    def __init__(self, program=None):
        self.alive = True
        self.bump = False
        if program is None:
            def program(percept):
                return raw_input('Percept=%s; action? ' % percept)
        assert callable(program)
        self.program = program

    def can_grab(self, thing):
        """Returns True if this agent can grab this thing.
        Override for appropriate subclasses of Agent and Thing."""
        return False

def TraceAgent(agent):
    """Wrap the agent's program to print its input and output. This will let
    you see what the agent is doing in the environment."""
    old_program = agent.program
    def new_program(percept):
        action = old_program(percept)
        print '%s perceives %s and does %s' % (agent, percept, action)
        return action
    agent.program = new_program
    return agent
def SimpleReflexAgentProgram(rules, interpret_input):
    "This agent takes action based solely on the percept. [Fig. 2.10]"
    def program(percept):
        state = interpret_input(percept)
        rule = rule_match(state, rules)
        action = rule.action
        return action
    return program

def ModelBasedReflexAgentProgram(rules, update_state):
    "This agent takes action based on the percept and state. [Fig. 2.12]"
    def program(percept):
        program.state = update_state(program.state, program.action, percept)
        rule = rule_match(program.state, rules)
        action = rule.action
        return action
    program.state = program.action = None
    return program
def rule_match(state, rules):
    "Find the first rule that matches state."
    for rule in rules:
        if rule.matches(state):
            return rule
loc_A, loc_B = (0, 0), (1, 0) # The two locations for the Vacuum world


def RandomVacuumAgent():
    "Randomly choose one of the actions from the vacuum environment."
    return Agent(RandomAgentProgram(['Right', 'Left', 'Suck', 'NoOp']))
def ReflexVacuumAgent():
    "A reflex agent for the two-state vacuum environment. [Fig. 2.8]"
    def program((location, status)):
        if status == 'Dirty': return 'Suck'
        elif location == loc_A: return 'Right'
        elif location == loc_B: return 'Left'
    return Agent(program)

def ModelBasedVacuumAgent():
    "An agent that keeps track of what locations are clean or dirty."
    model = {loc_A: None, loc_B: None}
    def program((location, status)):
        "Same as ReflexVacuumAgent, except if everything is clean, do NoOp."
        model[location] = status ## Update the model here
        if model[loc_A] == model[loc_B] == 'Clean': return 'NoOp'
        elif status == 'Dirty': return 'Suck'
        elif location == loc_A: return 'Right'
        elif location == loc_B: return 'Left'
    return Agent(program)



