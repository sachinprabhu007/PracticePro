#ASCII value of a character

while True:
	string = str(raw_input('Character : '))

	if len(string)==1:
		print "ASCII value of",string+" is",ord(string)
		#can also be written as 
	#	print "ASCII value of %s is %d "%(string,ord(string))
	#	print "ASCII value of %r is %r "%(string,ord(string))
		break
	else:
		print "Entered value is a string and not a char"
		continue

