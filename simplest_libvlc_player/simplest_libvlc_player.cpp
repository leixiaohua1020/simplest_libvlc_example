/**
 * 最简单的基于libVLC的播放器
 * Simplest libVLC Player
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序是一个最简单的基于libVLC的视频播放器。
 * 适合初学者学习libVLC。
 *
 * This example is the simplest Video Player based on libVLC.
 * Suitable for the beginner of libVLC.
 */
#include <Windows.h>
#include "vlc/vlc.h"

int main(int argc, char* argv[])
 {
     libvlc_instance_t * inst;
     libvlc_media_player_t *mp;
     libvlc_media_t *m;
     
	 libvlc_time_t length;
	 int width;
	 int height;
	 int wait_time=5000;

	 //libvlc_time_t length;

     /* Load the VLC engine */
     inst = libvlc_new (0, NULL);
  
     //Create a new item
	 //Method 1:
     //m = libvlc_media_new_location (inst, "file:///F:\\movie\\cuc_ieschool.flv");
	 //Screen Capture
	 //m = libvlc_media_new_location (inst, "screen://");
	 //Method 2:
     m = libvlc_media_new_path (inst, "cuc_ieschool.flv");
        
     /* Create a media player playing environement */
     mp = libvlc_media_player_new_from_media (m);

	 
     /* No need to keep the media now */
     libvlc_media_release (m);
 
     // play the media_player
     libvlc_media_player_play (mp);

	 //wait until the tracks are created
	 _sleep (wait_time);
	 length = libvlc_media_player_get_length(mp);
	 width = libvlc_video_get_width(mp);
	 height = libvlc_video_get_height(mp);
	 printf("Stream Duration: %ds\n",length/1000);
	 printf("Resolution: %d x %d\n",width,height);
	 //Let it play 
     _sleep (length-wait_time); 
    
     // Stop playing
     libvlc_media_player_stop (mp);
 
     // Free the media_player
     libvlc_media_player_release (mp);
 
     libvlc_release (inst);
 
     return 0;
 }