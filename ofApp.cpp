#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto rect_len = 30;
	auto center = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	auto radius_base = 300.f;
	
	for (int z = 0; z > -500; z -= 50) {

		for (auto x = 0; x < ofGetWidth(); x += rect_len) {

			for (auto y = 0; y < ofGetHeight(); y += rect_len) {

				auto rad = std::atan2(center.y - y, center.x - x);
				auto point = glm::vec2(radius_base * cos(rad), radius_base * sin(rad));
				auto radius = radius_base * ofMap(ofNoise(point.x * 0.0008, point.y * 0.0008, z * 0.005, ofGetFrameNum() * 0.01), 0, 1, 0.5, 1.0);
				point = glm::vec2(radius * cos(rad), radius * sin(rad));

				if (glm::distance(glm::vec2(x, y), center) > glm::length(point)) {

					ofNoFill();
					ofSetColor(239);
					ofDrawRectangle(glm::vec3(x, y, z), rect_len, rect_len);

					ofFill();
					ofSetColor(ofMap(z, -500, 0, 239, 0));
					ofDrawRectangle(glm::vec3(x, y, z), rect_len - 0.5, rect_len - 0.5);
				}
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}