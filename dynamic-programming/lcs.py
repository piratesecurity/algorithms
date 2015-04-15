string1="""Computer security is security applied to computing devices such as computers and smartphones, as well as computer networks such as private and public networks, including the whole Internet. The field includes all the processes and mechanisms by which digital equipment, information and services are protected from unintended or unauthorized access, change or destruction, and is of growing importance due to the increasing reliance of computer systems in most societies.[1] It includes physical security to prevent theft of equipment and information security to protect the data on that equipment. It is sometimes referred to as "cyber security" or "IT security". Those terms generally do not refer to physical security, but a common belief among computer security experts is that a physical security breach is one of the worst kinds of security breaches as it generally allows full access to both data and equipment."""


string2="""Cybersecurity is the process of applying security measures to ensure confidentiality, integrity, and availability of data. Cybersecurity attempts to assure the protection of assets, which includes data, desktops, servers, buildings, and most importantly, humans. The goal of cybersecurity is to protect data both in transit and at rest. Countermeasures can be put in place in order to increase the security of data. Some of these measures include, but are not limited to, access control, awareness training, audit and accountability, risk assessment, penetration testing, vulnerability management, and security assessment and authorization."""

solutions=[]

for i in range(len(string1)+1):
	solutions.append([-1]*(len(string2)+1))


def max(num1,num2):
	if num1>num2:
		return num1
	else:
		return num2
		

def lcs(ind1,ind2):
	for i in range(1,ind1):
		for j in range(1,ind2):
			if i==0 or j==0:
				solutions[i][j]=0
			elif string1[i-1]==string2[j-1]:
				solutions[i][j]=solutions[i-1][j-1]+1
			else:
				solutions[i][j]=max(solutions[i-1][j],solutions[i][j-1])

def find_string(ind1,ind2):
	result=""
	while (ind1>0 and ind2>0):
		if string1[ind1-1]==string2[ind2-1]:
			result = string1[ind1-1] +result
			ind1-=1
			ind2-=1
		else:
			if solutions[ind1][ind2-1] >solutions[ind1-1][ind2]:
				ind2-=1
			else:
				ind1-=1
	return result

lcs(len(string1)+1,len(string2)+1)

print "Length of the Largest common Subsequence is :",solutions[len(string1)][len(string2)]		
		
print "Largest common Subsequence is :\n",find_string(len(string1),len(string2))
