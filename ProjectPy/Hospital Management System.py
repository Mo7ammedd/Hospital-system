#write Doctor #1
def writeD():
    with open('DoctorPy.txt','a') as file :
        c = 'y'
        while c == 'y' :
          id = input("Enter Doctor ID :")
          name = input("Enter Doctor Name :")
          age = input("Enter Doctor Age :")
          Mobile = input("Enter Doctor Mobile number :")
          department = input("Enter Doctor work department:")
          salary = input("Enter Doctor salary :")
          file.write(id +'\t\t'+ name +'\t\t'+ age +'\t\t'+Mobile+'\t\t'+department+'\t\t'+salary+'\n')
          c = input('Do you want enter records again(y/n)?')
    print('File saved successfully')
    
#read Doctor #2   
def readD():
    with open('DoctorPy.txt','r') as file :
        print('Id\t\tName\t\tAge\t\tMobile\t\tdepartment\tsalary')
        print('-----------------------------------------------------------------------------------------------')
        for line in file :
            print(line, end='')

            
#search Doctor by id #3           
def searchByIdD():
  c='y'
  while c=='y':
     id = input('Enter Doctor ID to search For: ')
     with open('DoctorPy.txt','r') as file :
         flag = False
         for line in file :
             fileds = line.split('\t\t')
             if fileds[0] == id:
                 flag = True
                 print('Id\t\tName\t\tAge\t\tMobile\t\tdepartment\tsalary')
                 print('-----------------------------------------------------------------------------------------------')
                 print(line)
                 c = input('Do You Want to Search More Doctors (y/n)? : ')
         if not flag:
            print('Doctor Not found!')
            c = input('Do You Want to Search More Doctors (y/n)? : ')

#search Doctor by Name #4
def SearchByNameD():
    c='y'
    while c=='y':
        name=input('Enter Doctor Name to Search For: ')
        with open('DoctorPy.txt','r') as file:
            flag= False
            for line in file:
                fields = line.split('\t\t')
                if fields[1]== name:
                    flag=True
                    print('Id\t\tName\t\tAge\t\tMobile\t\tdepartment\tsalary')
                    print('-----------------------------------------------------------------------------------------------')
                    print(line)
            if not flag:
                print('Doctor not found')
        c = input('Do You Want to Search More Doctors (y/n)? : ')

#Update Doctor by id #5
def UpdateByIdD():
    c='y'
    while c=='y':
        import os
        id = input('Enter Doctor ID to Update: ')
        file = open('DoctorPy.txt', 'r')
        tempFile = open('Update.txt', 'w')
        flag = False
        for line in file:
            fields = line.split('\t\t')
            if fields[0] == id:
                flag = True
                id = input("Enter Doctor  new ID :")
                name = input("Enter Doctor  new Name :")
                age = input("Enter Doctor  new Age :")
                Mobile = input("Enter Doctor  new Mobile number :")
                department = input("Enter Doctor  new work department:")
                salary = input("Enter Doctor  new salary :")
                line = id + '\t\t' + name +'\t\t'+ age + '\t\t' + Mobile + '\t\t' + department + '\t\t'+ salary+ '\n'
            tempFile.write(line)
        file.close()
        tempFile.close()
        os.remove('DoctorPy.txt')
        os.rename('Update.txt','DoctorPy.txt')
        if not flag:
            print('Doctor not found')
        else:
            print('Doctor Updated\n')
            readD()
            print('\n')
        c = input('Do You Want to Update More Doctor Records (y/n)? : ')

#Update Doctor by Name #6
def UpdateByNameD():
    c='y'
    while c=='y':
        import os
        name = input('Enter Doctor Name to Update: ')
        file = open('DoctorPy.txt', 'r')
        tempFile = open('Update.txt', 'w')
        flag = False
        for line in file:
            fields = line.split('\t\t')
            if fields[1] == name:
                flag = True
                id = input("Enter Doctor ID :")
                name = input("Enter Doctor new Name :")
                age =input("Enter Doctor new Age :")
                Mobile = input("Enter Doctor new Mobile number :")
                department = input("Enter Doctor new work department:")
                salary = input("Enter Doctor new salary :")
                line = id + '\t\t' + name +'\t\t'+ age + '\t\t' + Mobile + '\t\t' + department + '\t\t'+ salary+ '\n'
            tempFile.write(line)
        file.close()
        tempFile.close()
        os.remove('DoctorPy.txt')
        os.rename('Update.txt','DoctorPy.txt')
        if not flag:
            print('Doctor not found')
        else:
            print('Doctor Updated\n')
            readD()
            print('\n')
        c = input('Do You Want to Update More Doctor Records (y/n)? : ')

#Delete Doctor by id #7
def DeleteD():
    import os
    readD()
    print('\n')
    id = input('Enter Doctor ID to Delete: ')
    file = open('DoctorPy.txt', 'r')
    tempFile = open('delete.txt', 'w')
    flag = False
    for line in file:
        fields = line.split('\t\t')
        if fields[0] == id:
            flag = True
        else:
            tempFile.write(line)
    file.close()
    tempFile.close()
    os.remove('DoctorPy.txt')
    os.rename('delete.txt','DoctorPy.txt')
    if not flag:
        print('Doctor not found')
    else:
        deleting()
        print('Doctor Deleted\n')
        readD()

def HomeD():
    c='y'
    while c == 'y':
        print('-------------------------')
        print('1: Add New Record')
        print('2: Read All Records')
        print('3: Search For Record')
        print('4: Update Record')
        print('5: Delete  Record')
        print('6: Go to Main menu')
        print('7: Exit  ')
        print('-------------------------\n')
        operation=input('Choose Operation: ')
        if operation=='1':
            print('+-------------------+')
            print('|        write      |')
            print('+-------------------+')
            writeD()
        elif operation=='2':
            print('+-------------------+')
            print('|        read       |')
            print('+-------------------+')
            readD()
        elif operation =='3':
            print('+-------------------+')
            print('|        search     |')
            print('+-------------------+')
            print('1- Search By Id')
            print('2- Search By Name')
            option=input('Choose Option: ')
            if option=='1':
                searchByIdD()
            elif option=="2":
                SearchByNameD()
            else:
                print("Wrong Choise")
        elif operation=="4":
            print('+-------------------+')
            print('|        update     |')
            print('+-------------------+')
            print('1- Update By Id')
            print('2- Update By Name')
            option = input('Choose Option: ')
            if option == '1':
                UpdateByIdD()
            elif option == '2':
                UpdateByNameD()
            else:
                print("Wrong Choise")
        elif operation=='5':
            print('+-------------------+')
            print('|        delete     |')
            print('+-------------------+')
            DeleteD()
        elif operation=='6':
            main()
        elif operation=='7':
            print('+-------------------+')
            print('|    Thank You (._.)|')
            print('+-------------------+')
            return
        else:
            print("Wrong Choise")
        c = input('\nDo You Want To Do More Operations (y/n)')
        print('\n')
##########################################################################################
#write Patient
def writep():
    with open('PatientPy.txt','a') as file :
        c = 'y'
        while c == 'y' :
          id = input("Enter patient ID :")
          name = input("Enter patient Name :")
          age = input("Enter patient Age :")
          Mobile = input("Enter patient Mobile number :")
          disease = input("The disease that the patient has :")
          treatment = input("The treatment is going on : ")
          file.write(id +'\t\t'+name+'\t\t'+age+'\t\t'+ Mobile+'\t\t'+disease+'\t\t'+treatment+'\n')
          c = input('Do you want enter records again(y/n)?')
    print('File saved successfully')
#####################################################################################################################################################
#Read Patient
def readP():
    with open('PatientPy.txt','r') as file :
        print('ID\t\tName\t\tAge\t\tMobile\t\tDisease\t\tTreatment')
        print('------------------------------------------------------------------------------------------------')
        for line in file :
            print(line, end='')
#####################################################################################################################################################
#search by ID
def searchByIdP():
  c='y'
  while c=='y':
     id = input('Enter Patient ID to search For: ')
     with open('PatientPy.txt','r') as file :
         flag = False
         for line in file :
             fileds = line.split('\t\t')
             if fileds[0] == id:
                 flag = True
                 print('ID\t\tName\t\tAge\t\tMobile\t\tDisease\t\tTreatment')
                 print('------------------------------------------------------------------------------------------------')
                 print(line)
                 c = input('Do You Want to Search More Patient (y/n)? : ')
         if not flag:
            print('Patient Not found!')
            c = input('Do You Want to Search More Patient (y/n)? : ')
            ###################

#############################################################################################################################
#Search by Name
def SearchByNameP():
    c='y'
    while c=='y':
        name=input('Enter Patient Name to Search For: ')
        with open('PatientPy.txt','r') as file:
            flag= False
            for line in file:
                fields = line.split('\t\t')
                if fields[1]== name:
                    flag=True
                    print('ID\t\tName\t\tAge\t\tMobile\t\tDisease\t\tTreatment')
                    print('------------------------------------------------------------------------------------------------')
                    print(line)
            if not flag:
                print('Patient not found')
        c = input('Do You Want to Search More Patients (y/n)? : ')
#############################################################################################################################
#Update 
def UpdateByIdP():
    c='y'
    while c=='y':
        import os
        id = input('Enter Patient ID to Update: ')
        file = open('PatientPy.txt', 'r')
        tempFile = open('UpdateP.txt', 'w')
        flag = False
        for line in file:
            fields = line.split('\t\t')
            if fields[0] == id:
                flag = True
                id = input("Enter patient new ID :")
                name = input("Enter patient new Name :")
                age = input("Enter patient new Age :")
                Mobile = input("Enter patient new Mobile number :")
                disease = input("The disease that the patient has :")
                treatment = input("The new treatment is going on : ")
                line = id + '\t\t' + name +'\t\t'+ age + '\t\t' + Mobile + '\t\t' + disease + '\t\t'+ treatment+ '\n'
            tempFile.write(line)
        file.close()
        tempFile.close()
        os.remove('PatientPy.txt')
        os.rename('UpdateP.txt','PatientPy.txt')
        if not flag:
            print('Patient not found')
        else:
            print('Patient Updated\n')
            readP()
            print('\n')
        c = input('Do You Want to Update More Patient Records (y/n)? : ')

########################################################################################################
def UpdateByNameP():
    c='y'
    while c=='y':
        import os
        name = input('Enter patient Name to Update: ')
        file = open('patientPy.txt', 'r')
        tempFile = open('UpdateP.txt', 'w')
        flag = False
        for line in file:
            fields = line.split('\t\t')
            if fields[1] == name:
                flag = True
                id = input("Enter patient new ID :")
                name = input("Enter patient new Name :")
                age = input("Enter patient new Age :")
                Mobile = input("Enter patient new Mobile number :")
                disease = input("The disease that the patient has :")
                treatment = input("The new treatment is going on : ")
                line = id + '\t\t' + name +'\t\t'+ age + '\t\t' + Mobile + '\t\t' + disease + '\t\t'+ treatment+ '\n'
            tempFile.write(line)
        file.close()
        tempFile.close()
        os.remove('patientPy.txt')
        os.rename('UpdateP.txt','patientPy.txt')
        if not flag:
            print('patient not found')
        else:
            print('patient Updated\n')
            readP()
            print('\n')
        c = input('Do You Want to Update More patient Records (y/n)? : ')
########################################################################################################
#Delete Doctor
def DeleteP():
    import os
    readP()
    print('\n')
    id = input('Enter Patient ID to Delete: ')
    file = open('PatientPy.txt', 'r')
    tempFile = open('deleteP.txt', 'w')
    flag = False
    for line in file:
        fields = line.split('\t\t')
        if fields[0] == id:
            flag = True
        else:
            tempFile.write(line)
    file.close()
    tempFile.close()
    os.remove('PatientPy.txt')
    os.rename('deleteP.txt','PatientPy.txt')
    if not flag:
        print('Patient not found')
    else:
        deleting()
        print('Patient Deleted\n')
        readP()
#############################################################################################################################
def HomeP():
    c='y'
    while c == 'y':
        print('-------------------------------')
        print('1: Add New Record')
        print('2: Read All Records')
        print('3: Search For Record')
        print('4: Update Record')
        print('5: Delete  Record')
        print('6: Go to Main menu')
        print('7: Exit  ')
        print('-------------------------------\n')
        operation=input('Choose Operation: ')
        if operation=='1':
            print('+-------------------+')
            print('|        write      |')
            print('+-------------------+')
            writep()
        elif operation=='2':
            print('+-------------------+')
            print('|        read       |')
            print('+-------------------+')
            readP()
        elif operation =='3':
            print('+-------------------+')
            print('|        search     |')
            print('+-------------------+')
            print('1- Search By Id')
            print('2- Search By Name')
            option=input('Choose Option: ')
            if option=='1':
                searchByIdP()
            elif option=="2":
                SearchByNameP()
            else:
                print("Wrong Choise")
        elif operation=="4":
            print('+-------------------+')
            print('|        update     |')
            print('+-------------------+')
            print('1- Update By Id')
            print('2- Update By Name')
            option = input('Choose Option: ')
            if option == '1':
                UpdateByIdP()
            elif option == '2':
                UpdateByNameP()
            else:
                print("Wrong Choise")
        elif operation=='5':
            print('+-------------------+')
            print('|        delete     |')
            print('+-------------------+')
            DeleteP()
        elif operation=='6':
            main()
        elif operation=='7':
            print('+-------------------+')
            print('|    Thank You (._.)|')
            print('+-------------------+')
            return
        else:
            print("Wrong Choise")
        c = input('\nDo You Want To Do More Operations (y/n)')
        print('\n')
##################################################deleting################################################################
def deleting():
    import os
    import time
    print('deleting', end='')
    for i in range(3):
        print('.', end='')
        time.sleep(0.4)
    time.sleep(0.4)
    print('\n')
######################################################################################################################################
def welcome():
    import os
    import time
    print('Welcome', end='')
    for i in range(6):
        print('.', end='')
        time.sleep(0.4)
    time.sleep(0.4)
    print('\n')    
################################################################
def main():
    
    c='y'
    while c == 'y':
        print('+----------------------------+')
        print('+ HOSPITAL MANAGEMENT SYSTEM +')
        print('+----------------------------+')
        welcome()
        print('---------------------------')
        print('1: Doctor Department')
        print('2: Paitent Department')
        print('3: Exit')
        print('---------------------------\n')
        operation=input('Choose Operation: ')
        if operation=='1':
            print('+-------------------------------+')
            print('|        Doctor Department      |')
            print('+-------------------------------+')
            HomeD()
        elif operation=='2':
            print('+-------------------------------+')
            print('|        patient Department     |')
            print('+-------------------------------+')
            HomeP()
        elif operation=='3':
            print('+-------------------------------+')
            print('|     >>>Thank You Xd:<<<       |')
            print('+-------------------------------+')
            return
        else:
            print("Wrong Choise")
        c = input('\nDo You Want To Do More Operations (y/n)')
        print('\n')

main()
