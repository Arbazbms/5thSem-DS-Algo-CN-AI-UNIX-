start=[5,4,-1,6,1,8,7,3,2]
goal=[1,2,3,4,5,6,7,8,-1]
visited_states=[]
def printFunction(state):
    for i in range(3):
        if(state[i*3] is not -1):
            print(state[i*3],end='\t')
        else:
            print('B',end='\t')
        if(state[i*3+1] is not -1):
            print(state[i*3+1],end='\t')
        else:
            print('B',end='\t')
        if(state[i*3+2] is not -1):
            print(state[i*3+2],end='\n')
        else:
            print('B',end='\n')         
        print('________________________________')

    print('\n\n\n')     
def movesPossible(state):
    moves=[]
    blank=state.index(-1)
    temp=state[:]
    global visited_states
    if blank >= 3:
        temp[blank-3], temp[blank] = temp[blank], temp[blank-3]
        print(visited_states)
        print(temp)
        if temp not in visited_states:
            moves.append('U')
        else:
            print('Check')
    if blank <= 5:
        temp[blank+3], temp[blank] = temp[blank], temp[blank+3]
        if temp not in visited_states:
            moves.append('D')
    if (blank)%3 < 2:
        temp[blank+1], temp[blank] = temp[blank], temp[blank+1]
        if temp not in visited_states:
            moves.append('R')
    if (blank)%3 > 0:
        temp[blank-1], temp[blank] = temp[blank], temp[blank-1]
        if temp not in visited_states:
            moves.append('L')
    print(moves)
    return moves

def boardState(state, goal):
    total=0
    for i in range(9):
        if state[i] is not -1:
            row1=i//3
            col1=i%3
            index=goal.index(state[i])
            row2=index//3
            col2=index%3
            total+=abs(row1-row2)+abs(col1-col2)
    print('Board State: ',total)
    return total      

def stateChange(state, move):
    blank=state.index(-1)
    if move == 'U':
        value=state[blank-3]        
    if move == 'D':
        value=state[blank+3]        
    if move == 'R':
        value=state[blank+1]        
    if move == 'L':
        value=state[blank-1]
          
    index=goal.index(value)
    print('Value is: ',value)
    currentindex=state.index(value)
    current=abs(currentindex//3-index//3)+abs(currentindex%3-index%3)
    print('Current Distance: ',current)
    
    total=abs(blank//3-index//3)+abs(blank%3-index%3)        
    print('Future distance: ',total)    
    return total-current
        
def makeMove(state, move):
    blank=state.index(-1)
    if move is 'U':
        state[blank-3], state[blank] = state[blank], state[blank-3]
    if move is 'D':
        state[blank+3], state[blank] = state[blank], state[blank+3]
    if move is 'R':
        state[blank+1], state[blank] = state[blank], state[blank+1]
    if move is 'L':
        state[blank-1], state[blank] = state[blank], state[blank-1]    
print('Goal')
printFunction(goal)
print('Start')
printFunction(start)

def search(state, goal, level=0):
    if boardState(state, goal) is 0 or level is 5:
        print('YOU WIN')
        return
    global visited_states
    print(visited_states)
    moves=movesPossible(state)
    movevalues=[]
    for move in moves:
        movevalues.append(stateChange(state, move))
    print(movevalues)
    mini=0
    for i in range(len(moves)):
        if movevalues[i] < movevalues[mini]:
            mini=i
    print(moves[mini])
    makeMove(state, moves[mini])
    visited_states.append(state)
    printFunction(state)
    search(state, goal, level+1)

visited_states.append(start)

search(start,goal)

