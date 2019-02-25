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
