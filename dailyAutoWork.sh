#!/bin/bash

####################################################################
# Script Name	: 
# Description	: 
# Args			: 
# Author		: Leon Cheng
# Email			: laohan1221@gmail.com
####################################################################

PATH=/bin:/sbin/:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
LOGFILE=/home/leon/log/daily.log
export LOGFILE
export PATH

DATE=`date +%Y-%m-%d\ %H:%M:%S`
cd /home/leon/test/

echo $DATE >> $LOGFILE 
# git commit -am "daily upload testfile" &>> $LOGFILE 
git add . &>> $LOGFILE 
git commit -m "daily upload testfile" &>> $LOGFILE 
echo $DATE >> $LOGFILE 
git push &>> $LOGFILE 


