uint128
=======


Testing the effectiveness of treating md5 checksums as numbers instead of strings for comparison purposes.

This is a basic implementation of unsigned 128bit numbers for amd64 hardware. No arithmetic operations are supported, only converting 32 character hex strings into uint128 and comparing them.

The purpose of this is to investigate an alternative method of handling md5 checksums by benchmarking straightforward string comparisons and then converting the checksums into 128 bit integers and performing the same benchmark again.

The benchmark test takes a list of 10000 md5 checksums and does a linear search for the final element thus performing 10000 comparison operations.

The results on my i5 Gentoo laptop were as follows:

    10,000 string comparisons --  195 µseconds
    10,000 uint128 comparisons -- 1 µsecond 
    
However, converting the 10000 strings into uint128s took

    2896 µseconds

This overhead is mostly due to a memcpy inside the create_uint128 function. This means that the conversion operation takes 15 times as long as a string comparison.

If we were to use a log₂(N) search algorithm such as a binary search to find a particular checksum in a list then it would be quicker to do string comparisons up until a list size of 32768 (2**15) items. After that it is more efficient to convert the list into uint128 numbers. This would also save space since a string representation of an md5 checksum is 33 bytes and an uint128 is just two 8 byte integers. 

