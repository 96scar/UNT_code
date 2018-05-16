/*
Names: Scarlett Jones and Michael "Kellen" Mills
Course: CSCE 2610.001 - Assembly Language and Computer Organization
Assignment: Program 2
Due Date: April 25, 2016 at 10:00 PM
Description: A C++ program that acts as a floating point multiplication hardware. The program 
reads two single precision floating points (in hexadecimal format) and outputs the product.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using namespace std;

string HexToBin(string hex);
string DecToHex(int dec);
string DecToBin(unsigned long int dec);
unsigned long int BinToDec(string bin);
string getS(string bin);
string getExponent(string bin);
string getFraction(string bin);
string addExponents(int de1, int de2);
string getSignificand(string s);
string multiplySignificands(string multiplier, string multiplicand);
string determineSign(string s1, string s2);
string getHexProduct(string s, string exp, string frac);
string normalFraction(string f);
int shiftAmount(string product);
string newExp(string old, int minus);

int main()
{
    /* 
        hex1: the 1st hex number input
        hex2: the 2nd hex number input
        bin1: convert 1st hex to binary
        bin2: convert 2nd hex to binary
        s1: sign one in binary
        s2: sign two in binary
        exp1: exponent one in binary
        exp2: exponent two in binary
        addexp: addition of exp1 and exp2 in binary
        frac1: fraction one in binary
        frac2: fraction two in binary
        sig1: significant one in binary
        sig2: significant two in binary
        sign: the resultant sign in binary
        dexp1: exponent one in decimal
        dexp2: exponent two in decimal
        shift: how many places to shift to normalize product
        finalFrac: string binary normalized fraction
        finalExp: string binary normalized exponent
        finalAns: the answer in hex
    */
    string hex1, hex2, bin1, bin2, s1, s2, exp1, exp2, addexp, frac1, frac2, sig1, sig2, sign, product, finalFrac, finalExp, finalAns;
    int shift, dexp1, dexp2;
    
    //first set of input with error checking
    cout << "Enter a single precision floating point (in hex): ";
    cin >> hex1;
    cout << endl;
    if(hex1.length() > 8)
    {
        cout << "Error: Input too long" << endl;
        cout << "Enter a single precision floating point (in hex): ";
        cin >> hex1;
        cout << endl;
    }
    else if(hex1.length() < 8)
    {
        cout << "Error: Input too short" << endl;
        cout << "Enter a single precision floating point (in hex): ";
        cin >> hex1;
        cout << endl;
    }
    
    //second set of input with error checking
    cout << "Enter another single precision floating point (in hex): ";
    cin >> hex2;
    cout << endl;
    if(hex2.length() > 8)
    {
        cout << "Error: Input too long" << endl;
        cout << "Enter another single precision floating point (in hex): ";
        cin >> hex2;
        cout << endl;
    }
    else if(hex2.length() < 8)
    {
        cout << "Error: Input too short" << endl;
        cout << "Enter another single precision floating point (in hex): ";
        cin >> hex2;
        cout << endl;
    }
    
    //convert hex inputs to binary
    bin1 = HexToBin(hex1);
    bin2 = HexToBin(hex2);

    //break up binary to just the sign
    s1 = getS(bin1);
    s2 = getS(bin2);

    //break the binary into the exponents
    exp1 = getExponent(bin1);
    exp2 = getExponent(bin2);
    

    //convert binary exponents into decimal exponents
    dexp1 = BinToDec(exp1);
    dexp2 = BinToDec(exp2);
    

    //add exponents and subtract bias
    addexp = addExponents(dexp1, dexp2);
    
    //break the binary to fractions
    frac1 = getFraction(bin1);
    frac2 = getFraction(bin2);
    
    //turn the fractions into significands
    sig1 = getSignificand(frac1);
    sig2 = getSignificand(frac2);
    
    
    //multiply the significands
    product = multiplySignificands(sig1, sig2);
    
    finalFrac = normalFraction(product);
    
    //determine shift amount to normalize
    shift = shiftAmount(product);
    
    //change the exponent to final answer
    finalExp = newExp(addexp, shift);
    
    //determine what sign the answer is
    sign = determineSign(s1, s2);
    
    //get the final answer in hex
    finalAns = getHexProduct(sign, finalExp, finalFrac);
    
    /*
    The section of code below merely prints out all the work we did
    Above, we call functions and set variables
    The variables are used below
    */
    cout << endl << "Step 1 - Add the exponents" << endl; //add the exponents and subtract bias
    cout << "Result (in binary): " << addexp << endl;
    
    cout << endl << "Step 2 - Multiply the significands" << endl; //multiplication hardware
    cout << "Result (in binary): " << product << endl;
    
    cout << endl << "Step 3 – Normalize the significand" << endl; // (-1)^s*(significand)^(power)
                                                                  // (-1)^s*(1.fraction)^(exponent-bias)
    cout << "Result of fraction (in binary): " << finalFrac << endl; //the significand without first 1, length 23
    cout << "Result of exponent (in binary): " << finalExp << endl; //adjust exponent as neccessary
    
    cout << endl << "Step 4 – Determine the sign" << endl; //compare s1 and s2 to determine
    cout << "Result (in binary): " << sign << endl;
    
    cout << endl << "Product (in hex): " << finalAns << endl; //concatenate binary strings together, call BinToHex

    return 0;
}

/*
Name: HexToBin
Parameters: 
Returns: a string with the binary in it
Description: Changes a string of hex into binary
*/
string HexToBin(string hex)
{
    string binary;
    int i;
    
    for(i=0; i<8; i++)
    {
        if(hex.at(i) == '0')
            binary += "0000";
        else if(hex.at(i) == '1')
            binary += "0001";
        else if(hex.at(i) == '2')
            binary += "0010";
        else if(hex.at(i) == '3')
            binary += "0011";
        else if(hex.at(i) == '4')
            binary += "0100";
        else if(hex.at(i) == '5')
            binary += "0101";
        else if(hex.at(i) == '6')
            binary += "0110";
        else if(hex.at(i) == '7')
            binary += "0111";
        else if(hex.at(i) == '8')
            binary += "1000";
        else if(hex.at(i) == '9')
            binary += "1001";
        else if(hex.at(i) == 'A' || hex.at(i) == 'a')
            binary += "1010";
        else if(hex.at(i) == 'B' || hex.at(i) == 'b')
            binary += "1011";
        else if(hex.at(i) == 'C' || hex.at(i) == 'c')
            binary += "1100";
        else if(hex.at(i) == 'D' || hex.at(i) == 'd')
            binary += "1101";
        else if(hex.at(i) == 'E' || hex.at(i) == 'e')
            binary += "1110";
        else if(hex.at(i) == 'F' || hex.at(i) == 'f')
            binary += "1111";
        else
        {
            cout << "Error: Incorrect hex input" << endl;
            exit(1);
        }
    }
    
    return binary;
}

/*
Name: DecToHex
Paramters: an int representing a binary number
Returns: a string representing a hex number
Description: converts decimal to hex
*/
string DecToHex(int dec)
{
    string hex;
    stringstream s;
    
    s.str() = " ";
    
    s << setw(8) << setfill('0') << std::hex << dec;
    
    hex = s.str();
    
    return hex;
}

/*
Name: DecToBin
Parameters: an unsigned long int representing a decimal number, and the length of binary wanted
Returns: a string representing a binary number
Description: converts decimal to binary
*/
string DecToBin(unsigned long int dec, int length)
{
    int i;
    unsigned long int quotient, dividend, divisor, remainder;
    int bi[length];
    string bin;
    quotient = 1;
    dividend = dec;
    divisor = 2;
    remainder = 0;
    
    for(i=0; i<length; i++)
    {
        bi[i] = 0;
    }
    
    i=length-1;
    while(quotient != 0)
    {
        quotient = dividend/divisor;
        remainder = dividend - (quotient*divisor);
        dividend = quotient;
        
        bi[i] = remainder;
        i--;
    }
    
    for(i=0; i<length; i++)
    {
        stringstream s;
        s.str() = " ";
        s << bi[i];
        
        bin += s.str();
    }
    
    return bin;
}

/*
Name: BinToDec
Paramters: a string representing a binary number
Returns: an unsigned long int representing a decimal number
Description: converts binary to decimal
*/
unsigned long int BinToDec(string bin)
{
    int length, i;
    unsigned long int add, dec;
    
    dec = 0;
    add = 1;
    length = bin.length();
    
    for(i = length-1; i >= 0; i--)
    {
        if(bin.at(i) == '1')
        {
            dec += add;
        }
        else
        {
            ;
        }
        
        add *= 2;
    }
    
    return dec;
}


/*
Name: getS
Parameters: a string of a binary number
Returns: a string of the first character of the bin string
Description: gets S from binary string
*/
string getS(string bin)
{
  string s;
  
  s = bin.at(0);
  
  return s;  
}

/*
Name: getExponent
Parameters: a string of a binary number
Returns: a string from 1 to 8 of the bin string
Description: gets Exponent from binary string
*/
string getExponent(string bin)
{
    string exponent;
    
    for(int i=1; i<9; i++)
        exponent += bin.at(i);
    
    return exponent;
}

/*
Name: getFraction
Parameters: a string of a binary number
Returns: a string from 9 to 31 of the bin string
Description: gets Fraction from binary string
*/
string getFraction(string bin)
{
    string fraction;
    
    for(int i=9; i<32; i++)
        fraction += bin.at(i);
    
    return fraction;
}

/*
Name: addExponents
Parameters: the two exponent values in a string
Returns: the sum of the exponents in binary
Description: add the exponent values (and substract the bias 127)
*/
string addExponents(int de1, int de2)
{
    int add;
    string sum;
    int bias = 127;
    
    add = de1 + de2 - bias; 
    
    sum = DecToBin(add, 8);
    
    return sum;
}

/*
Name: getSignificand
Parameters: a string that represents the binary fraction
Returns: a string that represenets the binary significand
Description: turns the fraction into a significand
*/
string getSignificand(string s)
{
    string significand;
    
    significand = '1' + s;
    
    return significand;
}

/*
Name: multiplySignificands
Parameters: the two significands in a string
Returns: the product of the significands in binary
Description: multiply the significands with multiplication hardware
*/
string multiplySignificands(string multiplier, string multiplicand) //significand is fraction and the extra 1 in front (i think)
{
    string plier, plicand, product; //product initially 48 bits of zero
    int i;
    unsigned long int dprod, dcand, dsum;
    stringstream s, t, u;
    s.str() = " ";
    t.str() = " ";
    u.str() = " ";
    
    //make sure multiplier has 24 bits by adding zeros to the front
    s << setw(24) << setfill('0') << multiplier;
    plier = s.str();
    
    
    //make sure multiplicand has 48 bits by adding zeros (to the front or back? i think the front)    
    t << setw(48) << setfill('0') << multiplicand;
    plicand = t.str();
    
    u << setw(48) << setfill('0');
    product = u.str();
    
    for(i=1; i<=24; i++)
    {
        
        //Test Multiplier in 0 bit for 1 or 0
        
        if(plier.at(23) == '1') //If multiplier at bit 0 is 1, add the multiplicand to product and place the result in product
        {
           //convert multiplicand to decimal
           dcand = BinToDec(plicand);
           
           //convert product to decimal
           dprod = BinToDec(product);
           
           //add them
           dsum = dcand + dprod;
           
           //convert addition into binary
           //save in product
           product = DecToBin(dsum, 48);
           
        }
        else //If multiplier at bit 0 is 0, continue on
        {
            ;
        }
        
        //Shift the multiplicand left 1 bit
       plicand.erase(plicand.begin());
       plicand = plicand + '0';
       
        //Shift the muliplier right 1 bit
        plier.erase(plier.begin()+23);
        plier = '0' + plier;
        //repeat 24 times
    }
    
    return product;
}

/*
Name: determineSign
Parameters: two signs to compare
Returns: the sign that comes after multiplying these
Description: tells you what the sign is after multiplying 2 numbers
*/
string determineSign(string s1, string s2)
{
    string sign;
    
    if(s1 == s2) //signs match
    {
        sign = '0'; //positive
    }
    else //signs don't match
    {
        sign = '1'; //negative
    }
    return sign;
}


/*
Name: getHexProduct
Parameters: s, exponent, fraction as binary strings
Returns: the hex product in string
Description: concatenates binary strings then calls BinToDec, then calls DecToHex
*/
string getHexProduct(string s, string exp, string frac)
{
    string hexp, bexp;
    int dexp;
    
    bexp = s + exp + frac;
    
    dexp = BinToDec(bexp);
    
    hexp = DecToHex(dexp);
    
    return hexp;
}

/*
Name: normalFraction
Parameters: the product significand
Returns: the normalized fraction
Description: makes the significand normalized
*/
string normalFraction(string f)
{
    string norm;
    int i;
    
    norm = f;
    
    for(i=0; i<(int)norm.length(); i++)
    {
        if(norm.at(i) == '1') //chop off that and ones before it and then stop
        {
            norm.erase(norm.begin(), norm.begin()+i+1);
            break;
        }
        else // leave alone?
        {
            ;
        }
    }
    
    if(norm.length() > 23)
    {
        norm.erase(norm.begin()+23, norm.end());
    }
    
    return norm;
}

/*
Name: shiftAmount
Parameters:string representing the end-product fraction in binary
Returns: the number of places to move the exponent over.
Description: function will move through the input string char-by-char until it finds the first one. 
It will then modify the result y = -x+1 where x is the index in the string at which the 1 was found and y is the return amount.
*/
int shiftAmount(string product)
{
    int shift=0;
    int i;
    i = product.length();
    for(shift=0;shift < i; shift++)
    {
        if(product.at(shift) == '0')
        {
            ;
        }
        else
        {
            switch(shift)
            {
                case 0: //the one was in the firt position, add 1
                    return 1;
                    break;
                case 1: 
                    return 0;
                    break;
                default: //position 3rd-48th the amount of shift is the index minus one...
                    shift-=1;
                    shift = shift*(-1); //negate
                    return shift;
            }
            break;
        }
    }
    //if there is a one before the second spot, shift=1
    //if there is a one in the second spot, shift=0
    //otherwise, keep looking and subtract 1 each time till we find a 1
    //always leave as soon as we find a 1
    return 0;
}

/*
Name: newExp
Parameters: string giving the exponent before normalization, int giving the amount to change our shift
Returns: a new string of binary to represent the new exponent
Description: Function will convert the old exp to decimal, add the shift value and then convert back to binary.
*/
string newExp(string before, int minus)
{
    int interphase = 0;
    string after;
    
    interphase = BinToDec(before); //old binary in decimal.
    interphase += minus; //new value of exp
    
    after = DecToBin((unsigned long int) interphase, 8); //new value in binary
    return after;
}