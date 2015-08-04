/*
 * TileLayer.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: Home
 */

#include "TileLayer.h"

TileLayer::~TileLayer()
{}

void TileLayer::update() {

}
void TileLayer::render() {

}

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets) :
	m_position(0, 0), m_velocity(0, 0), m_tilesets(tilesets) {

}
