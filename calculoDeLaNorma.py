import numpy as np

def err(t,exp):
    err=abs((t-exp)/t)
    return err

# N=int(input("Ingrese el tamaño de la Matriz Cuadrada: "))
# A=np.random.randint(0,21,size=(N,N))
A=np.array([[3,-1,4],[-5,0,2],[1,-2,6]])
N=3

###############################################################################
# MAIN

Suma1=np.zeros(N)
Sumai=np.zeros(N)
for i in range(0,N,1):
    sumai=0
    for j in range(0,N,1):
        sumai=sumai+abs(A[i,j])
    Sumai[i]=sumai

for j in range(0,N,1):
    suma1=0
    for i in range(0,N,1):
        suma1=suma1+abs(A[i,j])
    Suma1[j]=suma1

sumaf2=0
for j in range(0,N,1):
    for i in range(0,N,1):
        sumaf2=sumaf2+A[i,j]**2
sumaf=sumaf2**0.5 
Referenciai=np.linalg.norm(A,np.inf)
Referencia1=np.linalg.norm(A,1)
Referenciaf=np.linalg.norm(A,"fro")
   
print("########################################################################")
print("El valor calculado de la Norma 1 es:",max(Suma1))
print("El valor calculado de la Norma inf es:",max(Sumai))
print("El valor calculado de la Norma de Frobenius es:",sumaf)
print("########################################################################")
print("El valor de referencia para la Norma 1 es:", Referencia1)
print("El valor de referencia para la Norma inf es:", Referenciai)
print("El valor de referencia para la Norma de Frobenius es:", Referenciaf)