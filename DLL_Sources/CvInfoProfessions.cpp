#include "CvGameCoreDLL.h"

#include "CvInfoProfessions.h"
#include "CvXMLLoadUtility.h"
#include "CvDLLXMLIFaceBase.h"
#include "CvPlayerAI.h"
#include "CvGameAI.h"

//======================================================================================================
//					CvProfessionInfo
//======================================================================================================
//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   CvProfessionInfo()
//
//  PURPOSE :   Default constructor
//
//------------------------------------------------------------------------------------------------------
CvProfessionInfo::CvProfessionInfo() :
	m_iUnitCombatType(NO_UNITCOMBAT),
	/// info subclass - start - Nightinggale
	m_bfA(0),
	/// info subclass - end - Nightinggale
	///TK Professions Pedia
	m_iArtTagUnit(NO_UNITCLASS),
	m_ibNativesInvalid(false),
	m_ibEuropeInvalid(false),
	m_ibColonialInvalid(false),
	m_iUpgradeProfession(NO_PROFESSION),
	m_iLeadUnit(NO_UNITCLASS),
	m_iTaxCollectRate(0),
	m_iExperenceLevel(0),
	///TKe
	m_iSpecialBuilding(NO_SPECIALBUILDING),
	m_iCombatChange(0),
	m_iMovesChange(0),
	m_iWorkRate(0),
	m_iMissionaryRate(0),
	m_iPowerValue(0),
	m_iAssetValue(0),
	m_bWorkPlot(false),
	m_bCitizen(false),
	m_bWater(false),
	m_bScout(false),
	m_bCityDefender(false),
	m_bCanFound(false),
	m_bUnarmed(false),
	m_bNoDefensiveBonus(false),
	m_abFreePromotions(NULL),
	///TKs Med Battle Mod
	m_aiAltEquipmentTypes(NULL),
	m_abAltFreePromotions(NULL),
	//m_iCombatYieldsGathered(NULL),
	m_iRequiredBuilding(NO_BUILDINGCLASS),
	iRequiredPromotion(NO_PROMOTION),
	iCivType(-1),
	m_iFoundCityType(-1),
	///TKe
	m_iDefaultUnitAIType(NO_UNITAI)
{
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   ~CvProfessionInfo()
//
//  PURPOSE :   Default destructor
//
//------------------------------------------------------------------------------------------------------
CvProfessionInfo::~CvProfessionInfo()
{
	SAFE_DELETE_ARRAY(m_abFreePromotions);
	///TKs Med BM
	SAFE_DELETE_ARRAY(m_aiAltEquipmentTypes);
	SAFE_DELETE_ARRAY(m_abAltFreePromotions);
	///TKe
}
int CvProfessionInfo::getUnitCombatType() const
{
	return m_iUnitCombatType;
}

///TKs Professions Pedia
int CvProfessionInfo::getArtTagUnitClass() const
{
	return m_iArtTagUnit;
}
bool CvProfessionInfo::isNativesInvalid() const
{
	return m_ibNativesInvalid;
}
bool CvProfessionInfo::isEuropeInvalid() const
{
	return m_ibEuropeInvalid;
}
bool CvProfessionInfo::isColonialInvalid() const
{
	return m_ibColonialInvalid;
}
///TKs Med
int CvProfessionInfo::getUpgradeProfession() const
{
	return m_iUpgradeProfession;
}

int CvProfessionInfo::getLeadUnit() const
{
	return m_iLeadUnit;
}

int CvProfessionInfo::getRequiredBuilding() const
{
	return m_iRequiredBuilding;
}

int CvProfessionInfo::getRequiredPromotion() const
{
	return iRequiredPromotion;
}

int CvProfessionInfo::getCivilizationType() const
{
	return iCivType;
}
int CvProfessionInfo::getFoundCityType() const
{
	return m_iFoundCityType;
}

int CvProfessionInfo::getTaxCollectRate() const
{
	return m_iTaxCollectRate;
}

int CvProfessionInfo::getExperenceLevel() const
{
	return m_iExperenceLevel;
}
///TKe

int CvProfessionInfo::getSpecialBuilding() const
{
	return m_iSpecialBuilding;
}
int CvProfessionInfo::getCombatChange() const
{
	return m_iCombatChange;
}
int CvProfessionInfo::getMovesChange() const
{
	return m_iMovesChange;
}
int CvProfessionInfo::getWorkRate() const
{
	return m_iWorkRate;
}
int CvProfessionInfo::getMissionaryRate() const
{
	return m_iMissionaryRate;
}
int CvProfessionInfo::getPowerValue() const
{
	return m_iPowerValue;
}
int CvProfessionInfo::getAssetValue() const
{
	return m_iAssetValue;
}
bool CvProfessionInfo::isWorkPlot() const
{
	return m_bWorkPlot;
}
bool CvProfessionInfo::isCitizen() const
{
	return m_bCitizen;
}
bool CvProfessionInfo::isWater() const
{
	return m_bWater;
}
bool CvProfessionInfo::isScout() const
{
	return m_bScout;
}
bool CvProfessionInfo::isCityDefender() const
{
	return m_bCityDefender;
}
bool CvProfessionInfo::canFound() const
{
	return m_bCanFound;
}
bool CvProfessionInfo::isUnarmed() const
{
	return m_bUnarmed;
}
bool CvProfessionInfo::isNoDefensiveBonus() const
{
	return m_bNoDefensiveBonus;
}
int CvProfessionInfo::getYieldEquipmentAmount(int iYield) const
{
	for (uint i = 0; i < m_aYieldEquipments.size(); ++i)
	{
		const YieldEquipment& kYieldEquipment = m_aYieldEquipments[i];
		if (kYieldEquipment.iYieldType == iYield)
		{
			return kYieldEquipment.iYieldAmount;
		}
	}
	return 0;
}

bool CvProfessionInfo::isFreePromotion(int i) const
{
	FAssertMsg(i < GC.getNumPromotionInfos(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_abFreePromotions ? m_abFreePromotions[i] : false;
}

///TKs Med BM
int CvProfessionInfo::getAltEquipmentTypes(int i) const
{
    FAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_aiAltEquipmentTypes ? m_aiAltEquipmentTypes[i] : 0;
}
//int CvProfessionInfo::getAltEquipmentTypesArray()
//{
//	return m_aiAltEquipmentTypes;
//}
int CvProfessionInfo::getAltEquipmentAt(int i) const
{
	return m_aiAltEquipmentTypes[i];
}
//int CvProfessionInfo::getNumAltEquipmentTypes() const
//{
//	return (int)m_aiAltEquipmentTypes.size();
//}
bool CvProfessionInfo::isAltFreePromotion(int i) const
{
	FAssertMsg(i < GC.getNumPromotionInfos(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_abAltFreePromotions ? m_abAltFreePromotions[i] : false;
}
int CvProfessionInfo::getAltFreePromotionAt(int i) const
{
	return m_abAltFreePromotions[i];
}
//int CvProfessionInfo::getNumAltFreePromotion() const
//{
//	return (int)m_abAltFreePromotions.size();
//}

//bool* CvProfessionInfo::getAltFreePromotionArray()
//{
//	return m_abAltFreePromotions;
//}
///TKe
// MultipleYieldsProduced Start by Aymerick 22/01/2010
int CvProfessionInfo::getYieldsProduced(int i) const
{
	return m_aiYieldsProduced[i];
}

int CvProfessionInfo::getNumYieldsProduced() const
{
	return (int)m_aiYieldsProduced.size();
}
// MultipleYieldsProduced End
// MultipleYieldsConsumed Start by Aymerick 05/01/2010
///TKs Invention Core Mod v 1.0
int CvProfessionInfo::getYieldsConsumed(int i, PlayerTypes eCurrentPlayer) const
{

    if (getYieldsProduced(0) == YIELD_IDEAS && eCurrentPlayer != NO_PLAYER)
    {
        if (GET_PLAYER(eCurrentPlayer).isHuman())
        {
            CivicTypes eCurrentResearch = (CivicTypes)GET_PLAYER(eCurrentPlayer).getCurrentResearch();

            if (eCurrentResearch != NO_CIVIC)
            {
				CvCivicInfo& kCivicInfo = GC.getCivicInfo(eCurrentResearch);
                int iRequiredYield = 0;
                for (int iResearch = 0; iResearch < NUM_YIELD_TYPES; iResearch++)
                {
                    if (kCivicInfo.getRequiredYields(iResearch) > 0)
                    {
                        if (iRequiredYield == i)
                        {
                            return iResearch;
                        }
                        iRequiredYield++;
                    }
                    else
                    {
                        continue;
                    }

                }

                return YIELD_IDEAS;

            }
            else
            {
                return -1;
            }
        }

    }

	return m_aiYieldsConsumed[i];
}

int CvProfessionInfo::getNumYieldsConsumed(PlayerTypes eCurrentPlayer) const
{

    if (getYieldsProduced(0) == YIELD_IDEAS && eCurrentPlayer != NO_PLAYER)
    {
        CivicTypes eCurrentResearch = (CivicTypes)GET_PLAYER(GC.getGameINLINE().getActivePlayer()).getCurrentResearch();

        if (eCurrentResearch != NO_CIVIC)
        {
			CvCivicInfo& kCivicInfo = GC.getCivicInfo(eCurrentResearch);
            int iYieldsConsumed = 0;
            for (int iResearch = 0; iResearch < NUM_YIELD_TYPES; iResearch++)
            {
                if (kCivicInfo.getRequiredYields(iResearch) > 0)
                {
                    iYieldsConsumed++;
                }
            }

            return iYieldsConsumed;
        }
        else
        {
            return 0;
        }
    }
    ///TKe

	return (int)m_aiYieldsConsumed.size();
}

int CvProfessionInfo::getYieldsConsumedPedia(int i) const
{
	return m_aiYieldsConsumed[i];
}

int CvProfessionInfo::getNumYieldsConsumedPedia() const
{
	return (int)m_aiYieldsConsumed.size();
}
///TKe
// MultipleYieldsConsumed End
int CvProfessionInfo::getDefaultUnitAIType() const
{
    return m_iDefaultUnitAIType;
}

void CvProfessionInfo::read(FDataStreamBase* stream)
{
	// MultipleYieldsConsumed Start by Aymerick 05/01/2010
	int iNumElements;
	int iElement;
	// MultipleYieldsConsumed End
	CvInfoBase::read(stream);
	uint uiFlag=0;
	stream->Read(&uiFlag);		// flag for expansion
	stream->Read(&m_iUnitCombatType);
	stream->Read(&m_iDefaultUnitAIType);
	stream->Read(&m_iYieldProduced);
	stream->Read(&m_iYieldConsumed);
	stream->Read(&m_iSpecialBuilding);
	stream->Read(&m_iCombatChange);
	stream->Read(&m_iMovesChange);
	stream->Read(&m_iWorkRate);
	stream->Read(&m_iMissionaryRate);
	stream->Read(&m_iPowerValue);
	stream->Read(&m_iAssetValue);
	stream->Read(&m_bWorkPlot);
	stream->Read(&m_bCitizen);
	stream->Read(&m_bWater);
	stream->Read(&m_bScout);
	///TKs Professions Pedia
	stream->Read(&m_iTaxCollectRate);
	stream->Read(&m_iExperenceLevel);
	stream->Read(&m_ibNativesInvalid);
	stream->Read(&m_ibEuropeInvalid);
	stream->Read(&m_ibColonialInvalid);
	stream->Read(&m_iArtTagUnit);
	///TKs Med
	stream->Read(&m_iUpgradeProfession);
	stream->Read(&m_iLeadUnit);
	stream->Read(&m_iRequiredBuilding);
	stream->Read(&iRequiredPromotion);
	stream->Read(&iCivType);
	stream->Read(&m_iFoundCityType);
	///TKe
	stream->Read(&m_bCityDefender);
	stream->Read(&m_bCanFound);
	stream->Read(&m_bUnarmed);
	stream->Read(&m_bNoDefensiveBonus);

	m_aYieldEquipments.clear();
	int iYieldEquipmentSize = 0;
	stream->Read(&iYieldEquipmentSize);
	for(int i=0;i<iYieldEquipmentSize;i++)
	{
		YieldEquipment kEquipment;
		stream->Read(&kEquipment.iYieldType);
		stream->Read(&kEquipment.iYieldAmount);
		m_aYieldEquipments.push_back(kEquipment);
	}

	SAFE_DELETE_ARRAY(m_abFreePromotions);
	m_abFreePromotions = new bool[GC.getNumPromotionInfos()];
	stream->Read(GC.getNumPromotionInfos(), m_abFreePromotions);

	///TKs Med BM
	m_aiCombatGearTypes.read(stream, true); // CombatGearTypes - Nightinggale

	SAFE_DELETE_ARRAY(m_aiAltEquipmentTypes);
	m_aiAltEquipmentTypes = new int[NUM_YIELD_TYPES];
	stream->Read(NUM_YIELD_TYPES, m_aiAltEquipmentTypes);

	SAFE_DELETE_ARRAY(m_abAltFreePromotions);
	m_abAltFreePromotions = new bool[GC.getNumPromotionInfos()];
	stream->Read(GC.getNumPromotionInfos(), m_abAltFreePromotions);
	///TKe

	// MultipleYieldsProduced Start by Aymerick 22/01/2010
	stream->Read(&iNumElements);
	m_aiYieldsProduced.clear();
	for (int i = 0; i < iNumElements; ++i)
	{
		stream->Read(&iElement);
		m_aiYieldsProduced.push_back(iElement);
	}
	// MultipleYieldsProduced End
	// MultipleYieldsConsumed Start by Aymerick 05/01/2010
	stream->Read(&iNumElements);
	m_aiYieldsConsumed.clear();
	for (int i = 0; i < iNumElements; ++i)
	{
		stream->Read(&iElement);
		m_aiYieldsConsumed.push_back(iElement);
	}
	// MultipleYieldsConsumed End
}
void CvProfessionInfo::write(FDataStreamBase* stream)
{
	CvInfoBase::write(stream);
	uint uiFlag = 0;
	stream->Write(uiFlag);		// flag for expansion
	stream->Write(m_iUnitCombatType);
	stream->Write(m_iDefaultUnitAIType);
	stream->Write(m_iYieldProduced);
	stream->Write(m_iYieldConsumed);
	stream->Write(m_iSpecialBuilding);
	stream->Write(m_iCombatChange);
	stream->Write(m_iMovesChange);
	stream->Write(m_iWorkRate);
	stream->Write(m_iMissionaryRate);
	stream->Write(m_iPowerValue);
	stream->Write(m_iAssetValue);
	stream->Write(m_bWorkPlot);
	stream->Write(m_bCitizen);
	stream->Write(m_bWater);
	stream->Write(m_bScout);
	///TKs Professions Pedia
	stream->Write(m_iTaxCollectRate);
	stream->Write(m_iExperenceLevel);
	stream->Write(m_ibNativesInvalid);
	stream->Write(m_ibEuropeInvalid);
	stream->Write(m_ibColonialInvalid);
	stream->Write(m_iArtTagUnit);
	///TKs Med
	stream->Write(m_iUpgradeProfession);
	stream->Write(m_iLeadUnit);
	stream->Write(m_iRequiredBuilding);
	stream->Write(iRequiredPromotion);
	stream->Write(iCivType);
	stream->Write(m_iFoundCityType);
	///TKe
	stream->Write(m_bCityDefender);
	stream->Write(m_bCanFound);
	stream->Write(m_bUnarmed);
	stream->Write(m_bNoDefensiveBonus);

	stream->Write((int)m_aYieldEquipments.size());
	for(int i=0;i<(int)m_aYieldEquipments.size();i++)
	{
		stream->Write(m_aYieldEquipments[i].iYieldType);
		stream->Write(m_aYieldEquipments[i].iYieldAmount);
	}

	stream->Write(GC.getNumPromotionInfos(), m_abFreePromotions);
	///TKs Med BM
	m_aiCombatGearTypes.write(stream, true); // CombatGearTypes - Nightinggale
	stream->Write(NUM_YIELD_TYPES, m_aiAltEquipmentTypes);
	stream->Write(GC.getNumPromotionInfos(), m_abAltFreePromotions);
	///TKe

	// MultipleYieldsProduced Start by Aymerick 22/01/2010
	stream->Write(m_aiYieldsProduced.size());
	for (std::vector<int>::iterator it = m_aiYieldsProduced.begin(); it != m_aiYieldsProduced.end(); ++it)
	{
		stream->Write(*it);
	}
	// MultipleYieldsProduced End

	// MultipleYieldsConsumed Start by Aymerick 05/01/2010
	stream->Write(m_aiYieldsConsumed.size());
	for (std::vector<int>::iterator it = m_aiYieldsConsumed.begin(); it != m_aiYieldsConsumed.end(); ++it)
	{
		stream->Write(*it);
	}
	// MultipleYieldsConsumed End
}
bool CvProfessionInfo::read(CvXMLLoadUtility* pXML)
{
	CvString szTextVal;
	/*if (!CvInfoBase::read(pXML))
	{
		return false;
	}*/
	pXML->GetChildXmlValByName(szTextVal, "Combat");
	m_iUnitCombatType = pXML->FindInInfoClass(szTextVal);

	///TK Profession Pedia
	pXML->GetChildXmlValByName(szTextVal, "iFoundCityType");
	m_iFoundCityType = pXML->FindInInfoClass(szTextVal);
//m_iUpgradeProfession
	pXML->GetChildXmlValByName(szTextVal, "ArtTagUnitClass");
	m_iArtTagUnit = pXML->FindInInfoClass(szTextVal);
	pXML->GetChildXmlValByName(&m_ibNativesInvalid, "bNativesInvalid");
	pXML->GetChildXmlValByName(&m_ibEuropeInvalid, "bEuropeInvalid");
	pXML->GetChildXmlValByName(&m_ibColonialInvalid, "bColonialInvalid");

    pXML->GetChildXmlValByName(szTextVal, "RequiredPromotion");
	iRequiredPromotion = pXML->FindInInfoClass(szTextVal);

	pXML->GetChildXmlValByName(&iCivType, "CivType");
//	pXML->GetChildXmlValByName(szTextVal, "CivType");
//	iCivType = pXML->FindInInfoClass(szTextVal);

	///TKe

	pXML->GetChildXmlValByName(szTextVal, "DefaultUnitAI");
	m_iDefaultUnitAIType = pXML->FindInInfoClass(szTextVal);
	pXML->GetChildXmlValByName(szTextVal, "YieldProduced");
	m_iYieldProduced = pXML->FindInInfoClass(szTextVal);
	pXML->GetChildXmlValByName(szTextVal, "YieldConsumed");
	m_iYieldConsumed = pXML->FindInInfoClass(szTextVal);
	pXML->GetChildXmlValByName(szTextVal, "SpecialBuilding");
	/// XML load - start - Nightinggale
	//m_aszExtraXMLforPass3.push_back(szTextVal);
    m_iSpecialBuilding = pXML->FindInInfoClass(szTextVal);
	/// XML load - end - Nightinggale
	
	///TKs Med
    pXML->GetChildXmlValByName(szTextVal, "UpgradeProfession");
	/// XML load - start - Nightinggale
	//m_aszExtraXMLforPass3.push_back(szTextVal);
	m_iUpgradeProfession = pXML->FindInInfoClass(szTextVal);
	/// XML load - end - Nightinggale

	pXML->GetChildXmlValByName(szTextVal, "LeadUnit");
	m_iLeadUnit = pXML->FindInInfoClass(szTextVal);
	//pXML->GetChildXmlValByName(szTextVal, "LeadUnit");
	//m_aszExtraXMLforPass3.push_back(szTextVal);


    pXML->GetChildXmlValByName(szTextVal, "RequiredBuilding");
	/// XML load - start - Nightinggale
	//m_aszExtraXMLforPass3.push_back(szTextVal);
	m_iRequiredBuilding = pXML->FindInInfoClass(szTextVal);
	/// XML load - end - Nightinggale

	pXML->GetChildXmlValByName(&m_iTaxCollectRate, "iTaxCollectRate");
	pXML->GetChildXmlValByName(&m_iExperenceLevel, "iExperenceLevel");
	///tke

	pXML->GetChildXmlValByName(&m_iCombatChange, "iCombatChange");
	pXML->GetChildXmlValByName(&m_iMovesChange, "iMovesChange");
	pXML->GetChildXmlValByName(&m_iWorkRate, "iWorkRate");
	pXML->GetChildXmlValByName(&m_iMissionaryRate, "iMissionaryRate");
	pXML->GetChildXmlValByName(&m_iPowerValue, "iPower");
	pXML->GetChildXmlValByName(&m_iAssetValue, "iAsset");
	pXML->GetChildXmlValByName(&m_bWorkPlot, "bWorkPlot");
	pXML->GetChildXmlValByName(&m_bCitizen, "bCitizen");
	pXML->GetChildXmlValByName(&m_bWater, "bWater");
	pXML->GetChildXmlValByName(&m_bScout, "bScout");
	pXML->GetChildXmlValByName(&m_bCityDefender, "bCityDefender");
	pXML->GetChildXmlValByName(&m_bCanFound, "bCanFound");
	pXML->GetChildXmlValByName(&m_bUnarmed, "bUnarmed");
	pXML->GetChildXmlValByName(&m_bNoDefensiveBonus, "bNoDefensiveBonus");
	m_aYieldEquipments.clear();
	int *aiYieldAmounts;
	pXML->SetVariableListTagPair(&aiYieldAmounts, "YieldEquipedNums", NUM_YIELD_TYPES, 0);
	for (int i = 0; i < NUM_YIELD_TYPES; ++i)
	{
		if (aiYieldAmounts[i] != 0)
		{
			YieldEquipment kYieldEquipment;
			kYieldEquipment.iYieldType = i;
			kYieldEquipment.iYieldAmount = aiYieldAmounts[i];
			m_aYieldEquipments.push_back(kYieldEquipment);
		}
	}
	SAFE_DELETE_ARRAY(aiYieldAmounts);
	pXML->SetVariableListTagPair(&m_abFreePromotions, "FreePromotions", GC.getNumPromotionInfos(), false);
	///TKs Med BM
	// CombatGearTypes - start - Nightinggale
	m_aiCombatGearTypes.read(pXML, "CombatGearTypes");
	if (this->getUnitCombatType() != NO_UNITCOMBAT)
	{
		m_aiCombatGearTypes.set(true, this->getUnitCombatType());
	}
	// CombatGearTypes - end - Nightinggale
	pXML->SetVariableListTagPair(&m_aiAltEquipmentTypes, "AltEquipmentTypes", NUM_YIELD_TYPES, 0);
	pXML->SetVariableListTagPair(&m_abAltFreePromotions, "AltFreePromotions", GC.getNumPromotionInfos(), false);
	///TKe

	// MultipleYieldsProduced Start by Aymerick 22/01/2010
	if (gDLL->getXMLIFace()->SetToChildByTagName(pXML->GetXML(),"YieldsProduced"))
	{
		if (pXML->SkipToNextVal())
		{
			int iNumSibs = gDLL->getXMLIFace()->GetNumChildren(pXML->GetXML());
			m_aiYieldsProduced.clear();
			if (0 < iNumSibs)
			{
				if (pXML->GetChildXmlVal(szTextVal))
				{
					for (int j = 0; j < iNumSibs; j++)
					{
						m_aiYieldsProduced.push_back(pXML->FindInInfoClass(szTextVal));
						if (!pXML->GetNextXmlVal(&szTextVal))
						{
							break;
						}
					}
					gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
				}
			}
		}
		gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
	}
	// MultipleYieldsProduced End

	// MultipleYieldsConsumed Start by Aymerick 05/01/2010
	if (gDLL->getXMLIFace()->SetToChildByTagName(pXML->GetXML(),"YieldsConsumed"))
	{
		if (pXML->SkipToNextVal())
		{
			int iNumSibs = gDLL->getXMLIFace()->GetNumChildren(pXML->GetXML());
			m_aiYieldsConsumed.clear();
			if (0 < iNumSibs)
			{
				if (pXML->GetChildXmlVal(szTextVal))
				{
					for (int j = 0; j < iNumSibs; j++)
					{
						m_aiYieldsConsumed.push_back(pXML->FindInInfoClass(szTextVal));
						if (!pXML->GetNextXmlVal(&szTextVal))
						{
							break;
						}
					}
					gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
				}
			}
		}
		gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
	}
	// MultipleYieldsConsumed End

	/// info subclass - start - Nightinggale
	if (getSub(pXML))
	{
		pXML->GetChildXmlValByName(m_szTextKey, "Description");

		// restore XML
		gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
		gDLL->getXMLIFace()->SetToParent(pXML->GetXML());
	}
	/// info subclass - end - Nightinggale

	return true;
}

/// info subclass - start - Nightinggale
bool CvProfessionInfo::readSub(CvXMLLoadUtility* pXML, int* pSub)
{
	return CvInfoBase::readSub(pXML, pSub, &m_bfA, PROFESSION_INFO_BM_PARENT_NUM_BITS, PROFESSION_INFO_BM_PARENT_START, PROFESSION_INFO_BM_NUM_CHILDREN_NUM_BITS, PROFESSION_INFO_BM_NUM_CHILDREN_START, PROFESSION_INFO_BM_IS_PARENT);
}
/// info subclass - end - Nightinggale


#if 0
bool CvProfessionInfo::readPass3()
{
	if (m_aszExtraXMLforPass3.size() < 1)
	{
		FAssert(false);
		return false;
	}
	m_iSpecialBuilding = GC.getInfoTypeForString(m_aszExtraXMLforPass3[0]);
	///Tks Med
	m_iUpgradeProfession = GC.getInfoTypeForString(m_aszExtraXMLforPass3[1]);
	//m_iLeadUnit = GC.getInfoTypeForString(m_aszExtraXMLforPass3[2]);
	m_iRequiredBuilding = GC.getInfoTypeForString(m_aszExtraXMLforPass3[2]);
	m_aszExtraXMLforPass3.clear();
	///Tke
	return true;
}
#endif