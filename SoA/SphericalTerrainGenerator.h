///
/// SphericalTerrainGenerator.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 17 Dec 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Generates spherical terrain and meshes for a planet. 
/// Each planet should own one.
///

#pragma once

#ifndef SphericalTerrainGenerator_h__
#define SphericalTerrainGenerator_h__

class TerrainGenDelegate;

// Coordinate mapping for rotating 2d grid to quadcube positions
// Pain of i32v3, first is coordinates
const i32v3 CubeCoordinateMappings[6] = {
    i32v3(0, 1, 2), //TOP
    i32v3(1, 0, 2), //LEFT
    i32v3(1, 0, 2), //RIGHT
    i32v3(0, 2, 1), //FRONT
    i32v3(0, 2, 1), //BACK
    i32v3(0, 1, 2) //BOTTOM
};

// Multipliers for coordinate mappings
const f32v3 CubeCoordinateMults[6] = {
    f32v3(1.0f, 1.0f, 1.0f), //TOP
    f32v3(1.0f, -1.0f, 1.0f), //LEFT
    f32v3(1.0f, 1.0f, 1.0f), //RIGHT
    f32v3(1.0f, 1.0f, 1.0f), //FRONT
    f32v3(1.0f, -1.0f, 1.0f), //BACK
    f32v3(1.0f, -1.0f, 1.0f) //BOTTOM
};

class SphericalTerrainGenerator {
public:
    SphericalTerrainGenerator();
    ~SphericalTerrainGenerator();

    void generateTerrain(TerrainGenDelegate* data);

    void invokeTerrainGen(vcore::RPC* so) {
        m_rpcManager.invoke(so, false);
    }
private:
    /// Generates mesh using heightmap
    void buildMesh(TerrainGenDelegate* data);

    vcore::RPCManager m_rpcManager;
};

#endif // SphericalTerrainGenerator_h__