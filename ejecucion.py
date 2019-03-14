import os
import time
import sys
from random import randint, uniform, random

def inicio():
   print(os.getpid(), ": Soy el padre de todos los procesos, mi PID es: ", os.getpid())
   pid1 = os.fork()
   if not(pid1):
     os.execlp("gcc", "gcc", "SieteyMedio.c")
     os.exit(0)
   hijo = os.wait()
   print(os.getpid(), ": Mi hijo ", hijo, " ha finalizado la compilacion, procedere a ejecutar el programa")
   os.execlp("./a.exe", "a.exe")

if __name__ == "__main__":
	inicio()
