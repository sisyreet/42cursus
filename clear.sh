#!/bin/sh

echo '----------------------'
echo '\033[37;1;41mSize    Used    Avail\033[0m'
echo '----------------------'
df -h | grep Users | awk '{print $2 " = " $3 " + "  $4}'
#df -h | awk 'NR == 8{print $2 " = " $3 " + "  $4}'
#df -h | created/by/mmargene\Support/Peer/sh
rm -rf ~/Library/Application\ Support/Slack/Code\ Cache/
rm -rf ~/Library/Application\ Support/Slack/Cache/
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/
rm -rf ~/Library/Caches/*
rm -rf ~/.Trash/*
rm -rf ~/Library/Safari/*
rm -rf ~/.kube/cache/*
rm -rf ~/Library/Application\ Support/Code/CachedData/*
rm -rf ~/Library/Application\ Support/Code/User/workspaceStoratge/*
rm -fr ~/Library/Containers/com.docker.docker/Data/vms/*
rm -fr ~/Library/Containers/com.apple.Safari/Data/Library/Caches/*
df -h | grep Users | awk '{print $2 " = " $3 " + "  $4}'y
#df -h | awk 'NR == 8{print $2 " = " $3 " + "  $4}'
echo '----------------------'