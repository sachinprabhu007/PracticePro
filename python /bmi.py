#BMI calc

while True:
	ip = str(raw_input("Enter Count or end: "))
	print "Input: "+ip
	if ip == "Count":
		convFact = 0.45
		convFactor = 0.025
		getWeight = float(input('Weight in Pounds:'))
		getHeight = float(input('Height in Inches:'))
		weightInKG = getWeight * convFact
		HeightInM = (getHeight * convFactor) * (getHeight * convFactor)
		bmiIndex = weightInKG / HeightInM

		print "\n Healthy BMI ranges between 19 to 25"
		if 18 < bmiIndex < 26 :
			print 'Your BMI is '+str(bmiIndex)
			print 'You are Healthy \n '
		else:
			print 'Your BMI is '+str(bmiIndex)
			print('Your bodymass index isnt between Healthy range\n')
		continue
	else : 
			quit()