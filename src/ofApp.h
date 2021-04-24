#pragma once

#include "ofMain.h"
#include "Spring_Generators.h"
#include "Spring_Renderer.h"
#include "Spring_System.h"
#include "Spring_Updaters.h"

class ofApp : public ofBaseApp{
	const unsigned int rows = 40;
	const unsigned int cols = 40;
	ofEasyCam cam;
	Spring_System system = Spring_System(rows,cols);
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
