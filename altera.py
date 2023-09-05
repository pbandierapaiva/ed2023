# script para criar #defines numerados
entra = open("c.txt")
sai = open("c2.txt","w")
i=0
while(True):
    linha = entra.readline()
    if(linha==''): break
    sai.write(  linha.strip()+"\t"+str(i)+"\n" )
    i+=1

sai.close()
