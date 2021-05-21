#include <unistd.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/ioctl.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <linux/soundcard.h>  
#include <pthread.h>  
#define LENGTH 3  
#define RATE 8000  
#define SIZE 8  
#define CHANNELS 1   
unsigned char buf[LENGTH * RATE * SIZE * CHANNELS /8];   
int main()   
{   
    int fd_r,fd_w;   
    int arg;   
    int status;   
    pid_t pid;   
    int recing = 1,playing = 0;   
    pid = fork();   
    if(pid < 0){   
        perror("error in fork\n");   
    }   
    if(pid == 0){   
        fd_r = open("/dev/dsp",O_RDONLY);   
        if(fd_r < 0){   
            perror("open read of /dev/dsp failed");   
            exit(1);   
        }   
           
        arg = SIZE;   
        status = ioctl(fd_r,SOUND_PCM_WRITE_BITS,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_BITS ioctl failed");   
        if(arg != SIZE)   
            perror("unable to set sample size");   
           
           
        arg = CHANNELS;   
        status = ioctl(fd_r,SOUND_PCM_WRITE_CHANNELS,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_CHANNELS ioctl failed");   
        if(arg != CHANNELS)   
            perror("unable to set number of channels");   
           
        arg = RATE;   
        status = ioctl(fd_r,SOUND_PCM_WRITE_RATE,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_WRITE ioctl failed");   
       
        while(1)   
        {   
            if(playing== 0){   
                recing = 1;   
                printf("Say something:");   
                status = read(fd_r,buf,sizeof(buf));   
                /* recording*/  
                if(status != sizeof(buf))   
                    perror("read wrong number of bytes");   
                recing = 0;   
            }   
        }   
    }   
    else {   
        fd_w = open("/dev/dsp",O_WRONLY);   
        if(fd_w < 0)   
        {   
            perror("open write of /dev/dsp failed");   
            exit(1);   
        }   
           
        arg = SIZE;   
        status = ioctl(fd_w,SOUND_PCM_WRITE_BITS,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_BITS ioctl failed");   
        if(arg != SIZE)   
            perror("unable to set sample size");   
           
           
        arg = CHANNELS;   
        status = ioctl(fd_w,SOUND_PCM_WRITE_CHANNELS,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_CHANNELS ioctl failed");   
        if(arg != CHANNELS)   
            perror("unable to set number of channels");   
           
        arg = RATE;   
        status = ioctl(fd_w,SOUND_PCM_WRITE_RATE,&arg);   
        if(status == -1)   
            perror("SOUND_PCM_WRITE_WRITE ioctl failed");   
        while(1)   
        {   
            if(recing == 0){   
                playing = 1;   
                status = write(fd_w,buf,sizeof(buf));   
                /* playback */  
                if(status != sizeof(buf))   
                    perror("wrote wrong number of bytes");   
                status = ioctl(fd_w,SOUND_PCM_SYNC,0);   
                if(status == -1)   
                    perror("SOUND_PCM_SYNC ioctl failed");   
                playing = 0;   
            }   
        }   
    }   
} 
