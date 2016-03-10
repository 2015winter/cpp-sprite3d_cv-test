/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import java.io.IOException;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;

public class AppActivity extends Cocos2dxActivity {
	/*private static final String TAG="MyMP";  
    
    private SurfaceHolder mediaSurfaceHolder = null;  
    private MediaPlayer  mediaPlayer;  
    private boolean isMediaPlay = false;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		initVideo();
	}  
    
    @Override
	public Cocos2dxGLSurfaceView onCreateView() {
		// TODO Auto-generated method stub
		//return super.onCreateView();
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);  
        // Demo2 should create stencil buffer  
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);  
        return glSurfaceView;
	}

	static {  
        System.loadLibrary("cocos2dcpp");  
    }    
    private void initVideo(){  
        mediaSurfaceHolder = mediaView.getHolder();  
        mediaSurfaceHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);  
        mediaSurfaceHolder.addCallback(new MediaSurfaceHolderCallBack());  
    }  
    MediaPlayer.OnPreparedListener mPreparedListener = new MediaPlayer.OnPreparedListener() 
    {

		@Override
		public void onPrepared(MediaPlayer mp) {
			// TODO Auto-generated method stub
            Log.d(TAG,"onPrepared...");  
            int mVideoWidth = 0;  
            int mVideoHeight = 0;  
            mVideoWidth = mp.getVideoWidth();  
            mVideoHeight = mp.getVideoHeight();  
            mediaSurfaceHolder.setFixedSize(mVideoWidth, mVideoHeight);  
              
            mp.start();  
              
            isMediaPlay = true;  
		}
    	
    };
    
    private MediaPlayer.OnCompletionListener mCompletionListener = new MediaPlayer.OnCompletionListener() {  
        public void onCompletion(MediaPlayer mp) {  
            Log.d(TAG,"onCompletion...");  
            //isMediaPlay = false;  
            mp.seekTo(0);  
            mp.start();  
        }  
    };  
    
    private class MediaSurfaceHolderCallBack implements SurfaceHolder.Callback
    {

		@Override
		public void surfaceCreated(SurfaceHolder holder) {
			// TODO Auto-generated method stub
			  Log.d(TAG,"surfaceCreated...");  
              
	            mediaPlayer = new MediaPlayer();  
	            mediaPlayer.setOnPreparedListener(mPreparedListener);  
	            mediaPlayer.setOnCompletionListener(mCompletionListener);  
	              
	            try {  
	                mediaPlayer.setDataSource("E:/MyWorkSpace/WorkSpaceCocos2dx/MyCocosProjects/cpp-sprite3d-test-backup_01/Resources/nativeMedia.mp4");  
	                //mediaPlayer.setDataSource("/sdcard/video/aoa.mp4");  
	            } catch (IllegalArgumentException e) {  
	                e.printStackTrace();  
	            } catch (IllegalStateException e) {  
	                e.printStackTrace();  
	            } catch (IOException e) {  
	                e.printStackTrace();  
	            }  
	            mediaPlayer.setDisplay(mediaSurfaceHolder);  
	              
	            try {  
	                mediaPlayer.prepareAsync();   
	            } catch (IllegalStateException e) {  
	                e.printStackTrace();  
	            }   
		}

		@Override
		public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
			// TODO Auto-generated method stub
            Log.d(TAG,"surfaceChanged...,width="+width+", height="+height);  
		}

		@Override
		public void surfaceDestroyed(SurfaceHolder holder) {
			// TODO Auto-generated method stub
			  if( mediaPlayer.isPlaying() ){  
	                mediaPlayer.stop();  
	                mediaPlayer.release();  
	                mediaPlayer = null;  
	            }  
	  
	            if( mediaSurfaceHolder != null ){  
	                mediaSurfaceHolder = null;  
	            }  
		}
    	
    }*/
}
