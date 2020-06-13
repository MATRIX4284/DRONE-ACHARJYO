#tello-test
## Step1
Write the command set to be run in command.txt, for example:：
```
command
takeoff
up 20
down 20
left 50
right 50
forward 20
back 20
cw 90
ccw 90
flip l
flip r
flip f
flip b
flip f
flip bl
flip rb
flip fl
flip fr
delay 2
land
```
## Step2
Run the script
```
python3 tello_test.py command.txt
```
The command window will type each instruction and its reply. After the execution is finished, the commands will be stored in the log folder to name the test end time.
