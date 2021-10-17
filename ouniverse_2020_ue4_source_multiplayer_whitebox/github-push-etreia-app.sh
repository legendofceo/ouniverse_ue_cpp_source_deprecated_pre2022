echo Name of commit:
read commit_name

git add --all
git commit -m "$commit_name"
git push -u etreia-app master

read -p "All Done! Press any key to close ..."