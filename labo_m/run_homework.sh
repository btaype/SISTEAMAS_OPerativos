#!/bin/bash
time_s="$1"
P1="./p1"

echo "$i -------------> run program"
$P1 &
pid=$!
sleep 1
$"./p2" &
pid2=$!
sleep 1
$"./p3" &
pid3=$!
sleep 1
$"./p4" &
pid4=$!
sleep $time_s
kill $pid
kill $pid2
kill $pid3
kill $pid4
