#takes text file and returns most common word
import pathlib
from os.path import isfile, join
from os import listdir
def most_common_word(dir : pathlib.Path,sub:str)->dict:
    result = dict()
    for x in listdir(dir):
        path = join(dir,x)
        if isfile(path):
            if len(x)>=len(sub):
                if x[-len(sub):] == sub:             
                    file= open(path,'r',encoding= 'UTF-8')
                    listofwords = []
                    # \/ takes all words in text file and splits them up by spaces and symbols, sets listofwords 
                    # \/ to hold all words
                    for line in file.readlines():
                        stor = line.split()
                        for words in stor:
                            index = 0
                            finalappend = words
                            if words.isalpha() == False:
                                while index < len(words):
                                    if words[index].isalpha() !=True:
                                        listofwords.append(words[0:index-1].upper())
                                        if index + 1 < len(words):
                                            finalappend = words[index+1:]
                                    index +=1
                            if finalappend != "":
                                listofwords.append(finalappend.upper())

                    #makes list of words into dictionary with amount of every word 
                    output = {}
                    for word in listofwords:
                        if word in output:
                            output[word]+=1
                        else:
                            output[word]=1
                    #finds most common word in dict
                    while len(output)>0:
                        mostcommon=""
                        max = 0
                        for key in output:
                            if output[key] > max:
                                mostcommon = key
                                max = output[key]
                        if mostcommon in result:
                            result[mostcommon] += max
                        else:
                            result[mostcommon] = max
                        del output[mostcommon]
                        

    return result
                    

