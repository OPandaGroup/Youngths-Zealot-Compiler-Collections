int main(){
   FILE *file = openfile("test.txt","w");
   writetofile(file,"Hello World!");
   closefile(file);
}