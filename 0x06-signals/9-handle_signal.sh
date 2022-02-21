#!/bin/sh
#  handler for the signals SIGABRT, SIGIO and SIGTERM
trap "echo Nope" ABRT IO TERM
