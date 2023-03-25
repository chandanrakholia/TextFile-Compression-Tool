
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



## Demo

![Screenshot from 2023-03-25 11-53-09](https://user-images.githubusercontent.com/106094072/227701298-6ab8efb3-d7ec-4272-a88d-9c9f502e28f1.png)
![Screenshot from 2023-03-25 11-53-59](https://user-images.githubusercontent.com/106094072/227701296-2fc3f68f-a2ba-4c4d-ac99-785a493cb5cf.png)
![Screenshot from 2023-03-25 11-54-24](https://user-images.githubusercontent.com/106094072/227701293-f190d3ad-b3f4-49e8-8ed5-6c19fd82d74e.png)
![Screenshot from 2023-03-25 11-54-39](https://user-images.githubusercontent.com/106094072/227701291-9d738720-1c54-406a-ab5d-1417e5d2d35d.png)
![Screenshot from 2023-03-25 11-57-55](https://user-images.githubusercontent.com/106094072/227701288-6e4283dc-3a14-4151-a9d2-8fb2319eed9b.png)
![Screenshot from 2023-03-25 11-59-18](https://user-images.githubusercontent.com/106094072/227701282-119403e6-1d3f-4960-b092-9b6e7f415710.png)
![Screenshot from 2023-03-25 11-58-36](https://user-images.githubusercontent.com/106094072/227701286-9d321bc9-c5a3-4e33-8b15-4228d8633abc.png)
