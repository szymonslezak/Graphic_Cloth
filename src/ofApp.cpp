#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setNearClip(0.0f);
	cam.setFarClip(-1.0f);
	cam.setGlobalPosition({ 800,400,600 });
	const unsigned int R = 2;
	std::shared_ptr<Spring_Updater_Gravity> Upd_G = std::make_shared<Spring_Updater_Gravity>(4.81);
	std::shared_ptr<Spring_Updater_Spring> Upd_S = std::make_shared<Spring_Updater_Spring>(400.0);
	std::shared_ptr<Spring_Updater_Simple_Wind> Upd_Wind = std::make_shared<Spring_Updater_Simple_Wind>(-30.0);
	std::shared_ptr<Spring_Updater_Verlette> Upd_V = std::make_shared<Spring_Updater_Verlette>();
	//std::shared_ptr<Spring_Updater_Collision> Upd_C = std::make_shared<Spring_Updater_Collision>(1700, 1000,R);
	std::shared_ptr<Spring_Updater_Zero> Upd_Z = std::make_shared<Spring_Updater_Zero>();

	std::shared_ptr<Spring_Genartor_Mass> Gen_M = std::make_shared<Spring_Genartor_Mass>(2);
	std::shared_ptr<Spring_Genartor_Pos> Gen_P = std::make_shared<Spring_Genartor_Pos>(10);
	std::shared_ptr<Spring_Genartor_Simple_Connect> Gen_SC = std::make_shared<Spring_Genartor_Simple_Connect>();
	std::shared_ptr<Spring_Generator_D0> Gen_D = std::make_shared<Spring_Generator_D0>();


	std::shared_ptr<Spring_Renderer> Rend = std::make_shared<Spring_Renderer>(R);

	system.addUpdater(Upd_G);
	system.addUpdater(Upd_S);
	system.addUpdater(Upd_Wind);
	system.addUpdater(Upd_V);
	//system.addUpdater(Upd_C);
	system.addUpdater(Upd_Z);

	system.addGenerator(Gen_M);
	system.addGenerator(Gen_P);
	system.addGenerator(Gen_SC);
	system.addGenerator(Gen_D);

	system.set_renderer(Rend);

	system.generate();
	ofSetVerticalSync(true);
	ofBackground(20);
}

//--------------------------------------------------------------
void ofApp::update(){
	system.update(0.05);
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofEnableDepthTest();
	system.render();
	ofDisableDepthTest();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
