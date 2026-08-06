#pragma once

class Scene
{
public:
    virtual ~Scene();

    virtual void render() = 0;
};
