from random import randint
from time import sleep

def play():
    choice = str(input("rock, paper or scissors\n> ",)).lower()
    while(choice != "rock" and choice != "paper" and choice != "scissors"): 
        choice = str(input("rock, paper or scissors\n> ",))
    rnd = ["rock","paper","scissors"]
    rndNum = randint(0,2)
    sleep(0.3)
    print("> Machine chose %s"%rnd[rndNum])
    if(choice == rnd[rndNum]):
        sleep(0.3)
        print("It's a draw!")
    elif(choice.lower() == "rock"):
        if(rnd[rndNum] == "paper"):
            sleep(0.3)
            print("> You lost %s covers %s"%(rnd[rndNum], choice.lower()))
        elif(rnd[rndNum] == "scissors"):
            sleep(0.3)             
            print("> You won %s smashes %s"%(choice.lower(), rnd[rndNum]))
    elif(choice.lower() == "scissors"):
        if(rnd[rndNum] == "paper"):
            sleep(0.3)             
            print("> You won %s cuts %s"%(choice.lower(), rnd[rndNum]))
        elif(rnd[rndNum] == "rock"):
            sleep(0.3)             
            print("> You lost %s smashes %s"%(rnd[rndNum], choice.lower()))
    elif(choice.lower() == "paper"):
        if(rnd[rndNum] == "rock"):
            sleep(0.3)             
            print("> You won %s covers %s"%(choice.lower(), rnd[rndNum]))
        elif(rnd[rndNum] == "scissors"):
            sleep(0.3)             
            print("> You lost %s cuts %s"%(rnd[rndNum],choice.lower()))
    rndNum = randint(0,2)
play()
