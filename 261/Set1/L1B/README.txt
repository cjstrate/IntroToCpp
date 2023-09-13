For this lab, your tasks are as follows.  Provide the answers after each number.  Show your work for each step.

1a. Convert the decimal number 1,904,803,840 to 32-bit two's complement binary representation.
1904803840 // 2 : 0
952401920 // 2 : 0
476200960 // 2: 0
238100480 // 2 : 0
119050240 // 2 : 0
59525120 // 2 : 0
29762560 // 2 : 0
14881280 // 2 : 0
7440640 // 2 : 0
3720320 // 2 : 0
1860160 //2 : 0
930080 // 2 : 0
465040 // 2 : 0
232520 // 2 : 0
116260 // 2 : 0
58130 // 2 : 0
29065 // 2 : 1
14532 // 2 : 0
7266 // 2 : 0
3633 // 2 : 1
1816 // 2 : 0
908 // 2 : 0
454 // 2 : 0 
227 // 2 : 1
113 // 2 : 1
56 // 2 : 0
28 // 2 : 0
14 // 2 : 0
7 // 2 : 1
3 // 2 : 1
1 // 2 : 1
0 // 2 : 0

01110001100010010000000000000000

1b. Represent the value in hexadecimal. 


2a. Convert the decimal number -1,047,986,176 to 32-bit two's complement binary representation.
1,047,986,176 // 2 : 0
523993088 // 2 : 0
261996544 // 2 : 0
130998272 // 2 : 0
65499136 // 2 : 0
32749568 // 2 : 0 
16374784 // 2 : 0
8187392 // 2 : 0
4093696 // 2 : 0
2046848 // 2 : 0
1023424 // 2 : 0
511712 // 2 : 0
255856 // 2 : 0
127928 // 2 : 0
63964 // 2 : 0
31982 // 2 : 0
15991 // 2 : 1
7995 // 2 : 1
3997 // 2 : 1
1998 // 2 : 9
999 // 2 : 1
499 // 2 : 1
249 // 2 : 1
124 // 2 : 0
62 // 2 : 0
31 // 2 : 1
15 // 2 : 1
7 // 2 : 1
3 // 2 : 1
1 // 2 : 1

00111110011101110000000000000000 < flip + 1

11000001100010010000000000000000

2b. Represent the value in hexadecimal.


3a. Convert the decimal number 17.125 to 32-bit floating point precsision.
    17 // 2: 1
    8 // 2: 0
    4 // 2: 0
    2 // 2: 0
    1 // 2: 1
    10001
    0.125 
    0.125 * 2 = 0 + 0.25
    0.25 * 2 = 0 + 0.5
    0.5 * 2 = 1 + 0
    001

    00000000000000000000000010001.001

3b. Represent the value in hexadecimal.
    00000000000000000000000010001.001 => 10001.001 => 0001 0001 . 0010
    1 1 . 2 => 11.2
    11.2
4a. Convert the decimal number -17.125 to 32-bit floating point precision.
    17 // 2: 1
    8 // 2: 0
    4 // 2: 0
    2 // 2: 0
    1 // 2: 1
    10001
    0.125 
    0.125 * 2 = 0 + 0.25
    0.25 * 2 = 0 + 0.5
    0.5 * 2 = 1 + 0
    001

    1.0001001 * 2^4
    
4b. Represent the value in hexadecimal.
    10001.001 => 0001 0001 . 0010 => 1 1 . 2 => 11.2
    -11.2

5a. Convert the hexadecimal value 0xC3890000 to binary.
    C 3 8 9 => 12 3 8 9 => 1100 0011 1000 1001 => 1100001110001001

5b. Convert the binary to a signed decimal integer value using two's complement.
    -(2^15)+(2^14)+(2^9)+(2^8)+(2^7)+(2^3)+(2^0) = -15479

5c. Convert the binary to a floating point decimal value.
    (2^15)+(2^14)+(2^9)+(2^8)+(2^7)+(2^3)+(2^0) = 50057.0

6.  Using a terminal, perform the following steps.  List the commands used to perform the tasks:

- print the current directory you are in when the terminal opens
    pwd

- move into the lab1b_folder directory
    cd Set1/L1B/lab1b_folder

- list the contents of the directory
    ls

- move into the data directory
    cd data

- rename the misspelled file fil2.txt to be file2.txt
    mv fil2.txt file2.txt

- copy file1.txt to be file3.txt
    cp file1.txt file2.txt

- make a new file named file4.txt
    ni file4.txt

- move to the parent directory
    cd ..

- make a directory named bin
    mkdir bin

- compile main.cpp into an executable
    g++ main.cpp

- move the generated executable into the bin folder and rename it to be lab1b
    mv a.exe bin
    cd bin
    mv a.exe lab1b.exe

- print the current directory you are currently in
    pwd

- run the new executable from your current directory
    .\lab1b.exe

What to submit?
Submit this README.txt with the completed responses.