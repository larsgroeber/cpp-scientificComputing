#! /usr/bin/env bash

# 
# small script to send spam mails using mutt
# @author: Lars Groeber
# 

# terminate on error
set -e

#### GLOBALS ####
maxMails=5
timeInterval=1  # in minutes

#### FUNCTIONS ####

# function to send the mail
# @param: subject
#         email
#         body
function send
{
  echo $1" "$2" "$3
  #echo $3 | mutt -s $1 -- $2
}

# simple implementation, takes only arguments from commandline as inputs
# @param: subject
#         email
#         body
function simple
{
  if test ! $# -eq 3; then
    echo "Invalid number of arguments!"
    echo "Usage: "$0" subject email body"
    exit 1
  fi

  subject=$1
  email=$2
  body=$3

  for (( i = 1; i <= $maxMails; i++ )); do
    send $subject $email $body
    echo "Send "$i". mail to \""$email"\", going to sleep for "$timeInterval"min."\
         $(($maxMails-$i))" left."
    if test ! $i -eq $maxMails; then sleep $(($timeInterval*10)); fi
  done
}

simple $@

exit 0