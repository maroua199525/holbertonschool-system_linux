#!/usr/bin/env sh
# sends the signal SIGQUIT to a process, given its PID

if [ $# != 1 ]
then
	echo "Usage: $0 <pid>"
	exit 1
fi
kill -QUIT "$1"
