def numberToWords(num):
    dict1 = {'0':'Zero', '1':'One', '2':'Two', '3':'Three', '4':'Four', '5':'Five', '6':'Six','7':'Seven','8':'Eight', '9':'Nine', '10':'Ten','11':'Eleven','12':'Twelve','13':'Thirteen','14':'Fourteen','15':'Fifteen', '16':'Sixteen', '17':'Seventeen','18':'Eighteen','19':'Nineteen','20':'Twenty', '30':'Thirty', '40':'Forty', '50':'Fifty', '60':'Sixty','70':'Seventy','80':'Eighty','90':'Ninety', '100':'Hundred', '1000':'Thousand', '1000000':'Million','1000000000':'Billion','1000000000000':'Trillion' }
    checklist = [1000000000000,1000000000,1000000,1000,100,90,80,70,60,50,40,30,20]
    pointer = 0
    def funrec(dict1, num):
        pointer = 0
        if num <= 19:
            return dict1[str(num)]
        else:
            while(pointer<len(checklist)):
                if num//checklist[pointer] < 1:
                    pointer = pointer + 1
                else:
                    actnum = num*1
                    rem = num%checklist[pointer]
                    if num > 19 and num < 100 and rem != 0:
                        num = num//checklist[pointer]
                        return dict1[str(checklist[pointer])] + ' ' + funrec(dict1, rem)
                    elif num > 19 and num < 100 and rem == 0:
                        num = num//checklist[pointer]
                        return dict1[str(checklist[pointer])]
                    elif num > 100 and rem != 0:
                        num = num//checklist[pointer]
                        return funrec(dict1, num) + ' ' + dict1[str(checklist[pointer])] + ' ' + funrec(dict1, rem)
                    elif num > 100 and rem == 0:
                        num = num//checklist[pointer]
                        return funrec(dict1, num) + ' ' + dict1[str(checklist[pointer])]
                    elif rem != 0:
                        num = num//checklist[pointer]
                        return dict1[str(num)] + ' ' + dict1[str(checklist[pointer])] + ' ' + funrec(dict1, rem)
                    elif rem == 0:
                        num = num//checklist[pointer]
                        return dict1[str(num)] + ' ' + dict1[str(checklist[pointer])]
    if num == 0:
        return dict1[str(0)]
    else:
        return funrec(dict1, num)

user_input = int(input("Enter the number : "))
print("The number is in english words : " + numberToWords(user_input))
