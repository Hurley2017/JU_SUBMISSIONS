#! bin/bash
echo "Start : "
read username
input="$(grep $username /etc/passwd)"
IFS=':' read -ra files <<< "$input"
echo "Username : ${files[0]}"
echo "Password : ${files[1]}"
echo "User ID : ${files[2]}"
echo "Group ID : ${files[3]}"
echo "User ID Info : ${files[4]}"
echo "Home Directory : ${files[5]}"
echo "Command/Shell : ${files[6]}"
echo "End"