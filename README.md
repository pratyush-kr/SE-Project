# SE-Project
Software Engineering Project
# Instructions to Install Git
Step 1. Install Git Using this article: https://www.maketecheasier.com/install-git-bash-on-windows/
Step 2. Open Powershell
Step 3. Write "git config --global user.name 'user-name'"
Step 4. Write "git config --global user.email 'mail used to create git'"
Step 5. Write 'ssh-keygen' and create SSH key in the default location
Step 6. Go the location and open 'id_rsa.pub' file in text-editor
Step 7. Copy the ssh-key from there and go to this link: https://github.com/settings/keys
Step 8. Press the New SSH Key button
Step 9. Add your keys and save and exit browser.
Step 10. Open Powershell in the location you want your project file to be in
Step 11. Write "git clone git@github.com:pratyush-kr/SE-Project.git".
# Using git bash
To pull the changes from the main bracnch of your fork to your local machine write, 'git pull origin'
To Push the changes Write:
    1. 'git add .' -> this adds all the file that are changed in the loacal directory
    2. "git commit -m 'Your message (in short) changes that are made'" -> makes a commit in your local directory
    3. 'git push origin' -> Push your chnages to your fork/branch
To make sure your chages are merged in the main repository got to your fork make a pull request from browser
To merge changes in the main repository to your fork do fetch and merge in your fork from the browser and do a pull in bash