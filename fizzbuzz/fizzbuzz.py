x = 1
for x in range(1,101):
    if(x%15 == 0):
        print( "Fizzbuzz" )
    elif(x%3 == 0):
        print( "Fizz" )
    elif(x%5 == 0):
        print( "Buzz" )
    else:
        print( "%d"%(x))