#include <stdio.h>
#include <string.h>


/*
    Programm:
    Textdatei in mehrere Chunks zerlegen und nacheinander ausgeben.
    
    Testing für die Methode: 
    
    size_t read_file_chunk(char *filename, char *buf, int chunk_size, int chunk_id)
    
    in session.h
*/

int main () {
    size_t read;
    FILE *fp;
    
    //Hier den Dateinamen ändern:
    char *filename = "Sample.txt";
    int chunk_size = 100;

    char buf[chunk_size];
    int counter = 0;

    int chunk_id = 0;

    //Datei öffnen:
    fp = fopen(filename, "r+b");
    if (fp == NULL){
        printf("Can not open: %s\n", filename);
        return -1;
    }

    //Größe der Datei bestimmen.
    //Zeiger zum Ende der Datei springen lassen:
    fseek(fp, 0, SEEK_END);
    int data_size = ftell(fp);
    printf("\nData Größe: \n%d\n", data_size);

    //wieder an den Anfang springen:
    fseek(fp, 0, SEEK_SET);

    //Mit fseek SEEK_SET aktuelle Position:
    int pos = fseek(fp, 0, SEEK_SET);
    printf("\nPOS: \n%d\n", pos);


    //lesen bis zum ende der Datei:
    while( pos != EOF ){
        //sizeof(char) = 1
        fread(buf, sizeof(char), chunk_size, fp);
    
        printf("\nINHALT: \n%s\n", buf);
        printf("\nChunk No: \n%d\n", chunk_id);
        
        //nächste Position:
        //pos = getc(fp);
        chunk_id++;
        //int next_pos = next_pos + (chunk_size*chunk_id);
        pos = getc(fp);
        
    }

    printf("\nÜbertragene Chunks: \n%d\n", chunk_id);
    printf("\n Soll: %d\n", data_size);
    

    /* do
    {
        read = fread(buf, sizeof(char), chunk_size, fp);
        counter += read;

        //fseek


        printf("Chunkid: %d", chunk_id);
        
    } while (counter < chunk_id && read == chunk_size); */
    
    fclose(fp);

    return 0;
}
