#3.	Write shell scripts accept a file as a command line argument and display whether it is ordinary file or directory file and display their attributes.

#!/bin/shell
arg=$1
if [ -d "${arg}" ] ; then
    echo "$arg is a directory";
    ls -l $arg
else
    if [ -f "${arg}" ]; then
        echo "${arg} is an ordinary file";
        ls -l $arg
    else
        echo "${arg} is not valid";
        exit 1
    fi
fi
