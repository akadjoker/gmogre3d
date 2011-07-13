#ifndef OGRE_LIGHT_MAP_H
#define OGRE_LIGHT_MAP_H

#include "../boost_1_42/boost/smart_ptr/shared_ptr.hpp"


namespace cimg_library
{
    template<typename T> struct CImg;
};
 
class CLightMap : public Ogre::ManualResourceLoader
{
public:
    CLightMap(Ogre::SubEntity* pSubEntity, Ogre::Real PixelsPerUnit = 0, int iTexSize = 512, int iLightIntensityCallback = -1, bool bDebugLightmaps = false);
    ~CLightMap(void);
 
    void loadResource(Ogre::Resource *resource);
    Ogre::String GetName();
    static void ResetCounter();
 
    struct SortCoordsByDistance
    {
       bool operator()(std::pair<int, int> &left, std::pair<int, int> &right)
        {
            return (left.first*left.first + left.second*left.second) < 
                   (right.first*right.first + right.second*right.second);
        }
    };
 
    void CreateLightmap();
    void SetBlur(Ogre::Real blur);
    void SetLightSource(const Ogre::Vector3 &pos, Ogre::uint8 ambient_level);
    void SetIntensityCallback(int iLightIntensityCallback);
    void SaveLightmapTexture(Ogre::String filename);

protected:
    void LightTriangle(const Ogre::Vector3 &P1, const Ogre::Vector3 &P2, const Ogre::Vector3 &P3,
                       const Ogre::Vector3 &N1, const Ogre::Vector3 &N2, const Ogre::Vector3 &N3,
                       const Ogre::Vector2 &T1, const Ogre::Vector2 &T2, const Ogre::Vector2 &T3);
    Ogre::uint8 GetLightIntensity(const Ogre::Vector3 &Position, const Ogre::Vector3 &Normal);
    bool CalculateLightMap();
    void AssignMaterial();
    void CreateTexture();
    void FillInvalidPixels();
    static void BuildSearchPattern();
 
    /// Convert between texture coordinates given as reals and pixel coordinates given as integers
    inline int GetPixelCoordinate(Ogre::Real TextureCoord);
    inline Ogre::Real GetTextureCoordinate(int iPixelCoord);
 
    /// Calculate coordinates of P in terms of P1, P2 and P3
    /// P = x*P1 + y*P2 + z*P3
    /// If any of P.x, P.y or P.z are negative then P is outside of the triangle
    Ogre::Vector3 GetBarycentricCoordinates(const Ogre::Vector2 &P1, const Ogre::Vector2 &P2, const Ogre::Vector2 &P3, const Ogre::Vector2 &P);
    /// Get the surface area of a triangle
    Ogre::Real GetTriangleArea(const Ogre::Vector3 &P1, const Ogre::Vector3 &P2, const Ogre::Vector3 &P3);
 
    Ogre::TexturePtr m_Texture;
    Ogre::MaterialPtr m_Material;
    Ogre::MaterialPtr m_PrevMaterial;
    Ogre::SubEntity* m_pSubEntity;
    boost::shared_ptr<cimg_library::CImg<unsigned char> > m_LightMap;
    Ogre::String m_LightMapName;
    int m_iTexSize;
    int m_iCoordSet;
    static int m_iLightMapCounter;
    Ogre::Real m_PixelsPerUnit;
    static std::vector<std::pair<int, int> > m_SearchPattern;
    bool m_bDebugLightmaps;
    int m_iLightIntensityCallback;
    Ogre::Real m_fBlurAmount;
    Ogre::Vector3 m_light_pos;
    Ogre::uint8 m_ambient_level;
};
 
int CLightMap::GetPixelCoordinate(Ogre::Real TextureCoord)
{
    int iPixel = (int)(TextureCoord*m_iTexSize);
    if (iPixel < 0)
        iPixel = 0;
    if (iPixel >= m_iTexSize)
        iPixel = m_iTexSize-1;
    return iPixel;
}
 
Ogre::Real CLightMap::GetTextureCoordinate(int iPixelCoord)
{
    return (Ogre::Real(iPixelCoord)+0.5)/Ogre::Real(m_iTexSize);
}


class CEntityLightMap
{
public:
    CEntityLightMap(Ogre::Entity* pEntity, Ogre::Real PixelsPerUnit = 0, int iTexSize = 512, int iLightIntensityCallback = -1, bool bDebugLightmaps = false)
    {
        int i, iNumSubEntities = pEntity->getNumSubEntities();
        for (i=0; i<iNumSubEntities; ++i)
        {
            boost::shared_ptr<CLightMap> LightMap(new CLightMap(pEntity->getSubEntity(i), PixelsPerUnit, iTexSize, iLightIntensityCallback, bDebugLightmaps));
            m_LightMaps.push_back(LightMap);
        }
    }
 
    
    void SetBlur(Ogre::Real blur)
    {
        for (size_t i=0; i<m_LightMaps.size(); ++i)
        {
            boost::shared_ptr<CLightMap> lightmap = m_LightMaps[i];
            lightmap->SetBlur(blur);
        }
    }

    void SetLightSource(const Ogre::Vector3 &pos, Ogre::uint8 ambient_level)
    {
       for (size_t i=0; i<m_LightMaps.size(); ++i)
        {
            boost::shared_ptr<CLightMap> lightmap = m_LightMaps[i];
            lightmap->SetLightSource(pos, ambient_level);
        }
    }

    void SetIntensityCallback(int iLightIntensityCallback)
    {
        for (size_t i=0; i<m_LightMaps.size(); ++i)
        {
            boost::shared_ptr<CLightMap> lightmap = m_LightMaps[i];
            lightmap->SetIntensityCallback(iLightIntensityCallback);
        }
    }

    void CreateLightmap()
    {
        for (size_t i=0; i<m_LightMaps.size(); ++i)
        {
            boost::shared_ptr<CLightMap> lightmap = m_LightMaps[i];
            lightmap->CreateLightmap();
        }
    }

    void SaveLightmapTextures(Ogre::String filename)
    {
        size_t pos = filename.find_last_of(".");
        Ogre::String ext = filename.substr(pos, filename.length() - pos);
        Ogre::String basename = filename.replace(pos, filename.length() - pos, "");

        for (size_t i=0; i<m_LightMaps.size(); ++i)
        {
            boost::shared_ptr<CLightMap> lightmap = m_LightMaps[i];
            lightmap->SaveLightmapTexture(basename + "_sub" + Ogre::StringConverter::toString(i) + ext);
        }
    }

protected:
   std::vector<boost::shared_ptr<CLightMap> > m_LightMaps;
};

#endif
