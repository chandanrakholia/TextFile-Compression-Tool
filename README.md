
# Text File Compression Tool

It is based on Huffman coding Algorithm.
Made entirely on C++.


## About
Huffman coding is a lossless data compression algorithm.  

The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters.  
   
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 
## Run Locally

Clone the project

```bash
  git clone https://github.com/chandanrakholia/TextFile-Compression-Tool

```
Navigate to the project directory.

```bash
  cd TextFile-Compression-Tool-main
```

Put your textFile in this directory.

for Encoding:
```bash
  g++ encode.cpp -o en
  ./en <fileName.txt> <password>
```
<password> is of 4 characters, which is optional.

for Decoding:
```bash
  g++ decode.cpp -o de
  ./de <fileName.dat> <password>
```
<password> is same as you had earlier used for Encoding, It is optional if you had not use password.


