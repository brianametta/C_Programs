print("Assignment #5-2, Briana Wright, masc1429")

for i = 1,100,1 do

        --Print FizzBuzz if i is divisible by 3 and 5
        if i%3 == 0 and i%5 == 0 then
                print("FizzBuzz")

        --Print Fizz if i is divisible by 3
        elseif i%3 == 0 then
                print("Fizz")

        --Print Buzz if i is divisible by 5
        elseif i%5 == 0 then
                print("Buzz")

        else
                print(i)
end
end