# put_float
Making a float to string converter 100% accurate and working


performances:
* 40000 string
	* LDBL_MAX =		419.40 s
*  
	* LDBL_MAX =		230.78 s
	* LDBL_MIN =		  4.46 s
	* LDBL_TRUE_MIN =	  4.47 s
* free string "added"
	* LDBL_MAX =		227.66 s
	* LDBL_MIN =		  4.43 s
	* LDBL_TRUE_MIN =	  4.45 s
* changing the way integer numbers are calculated
	* LDBL_MAX =		  4.19 s
	* LDBL_MIN =		  4.43 s
	* LDBL_TRUE_MIN =	  4.47 s :(
* changing the char string "strnbr" of 21500 chars to a unsigned long long array:
	* LDBL_MAX =		  0.31 s
	* LDBL_MIN =		  0.09 s
	* LDBL_TRUE_MIN =	  0.31 s


```c
int		ullong_to_printf(ullong *meganbr)
{
	int i;

	i = 0;
	while (i < MEGALEN)
	{
		if (meganbr[i])
			printf("%018lld.", meganbr[i]);
		i++;
	}
	return (0);
}
`
