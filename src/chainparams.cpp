// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019 The Mktcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x00000edb03823e6b6fb39e27b3a6dfb9a80111fb9fb02980cc0096ceb588a8e7"))
    (227006, uint256("0x28c89445c326d91e34208d5427623688da76703af32b16daa9c404eab55300c8"))
    (226998, uint256("0x2500bb8d08c3e2de1df127ba612c93c351d3933636498f2c2221d121bbb3262a"))
    (226985, uint256("0x413c07a5626040c57084ae4f600ead41d7e218070d018eeea872698b4b03cad1"))
    (226964, uint256("0xf5eee894a173d6338de79ef8a506caf2ba4add77f37ea98d2763e2ddf958f3c1"))
    (226930, uint256("0x358edeb7bb94f62b488076e226a2ec3406fdf61e707fa73af787b68ec7bf66de"))
    (226875, uint256("0x3b828178e96777f8658d77bf661df04cb6ffa42d53bb7ab4c2ca34c3673b882f"))
    (226786, uint256("0x053b2360582c2ddb14af03ec0f22cdd65999e5df1739ab46d7d2dd499165a5a7"))
    (226642, uint256("0xa1312923fbb749d65223f5d5f3de5d699006c27e55a5e09a967ecd9636a5e649"))
    (226409, uint256("0x95633f54c852ebbf7fba76f3e844b8c4d2bfa0628d601c7372b7bf902b440e06"))
    (226032, uint256("0xaa919e7ff0d4d35f6a2ffa9ff9c913603eff047da8aef2d9c5e92ab9e10b05cf"))
    (225422, uint256("0x33f45fe9ca1f19b35d1c78941d456b490473f7a53aaba4097aed3011f8316ca9"))
    (224435, uint256("0xa8e1e9548de23f8398adb7aad12f170ba04115515bbf1e7c4c5f474e2affad38"))
    (222838, uint256("0x7468258f8379679dd091216c1b24de124db59e44025e63cfe74503930428e9ad"))
    (220254, uint256("0xb10d573482c56673009ed2b714d4e1a5fa28b7abceb38118add2972247f60bb9"))
    (216073, uint256("0x8e518a47a1ebf6679c084857eb5599154642e2598521e9ce16a0ccc1dde01e47"))
    (209308, uint256("0x24859402efbcc4175e813497a7ff99d17d74b1e1d17ff6ecd5c2dbe31d7a8ed5"))
    (198362, uint256("0x66c93eadf15095bc2ea07dc90d90860f01cef524ee25e1ac6ed802f159f742a6"))
    (180651, uint256("0x75c4d1b6773653cd1b7b401d7af99952f43962e6134cec1db82988dd948d247c"))
    (151994, uint256("0xc4523014b790da85d39e1d86250732ce2262ecb50386fe17b8307ed2f0e450c1"))
    (105626, uint256("0x947e6667d4cbf4ac3771eb4c8160b347c7f7315ebf872293b41afb68a5e7837d"))
    (30601, uint256("0x60ad06d2dd0678d8f41a015b06fd1bb101381d53c2bc492e4566ddc631512a0f"))
    ;


static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1610161184, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1570470324,
    0,
    250
};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1570470444,
    0,
    100
};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x2d;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x21;
        pchMessageStart[3] = 0x2a;
        vAlertPubKey = ParseHex("043eb21c3fba131564544f746a9d0bd7003e63a0fee8c900bf1c63b3ac00f05134fc67c765a8f2e7ef691b645cd8fb5034eb3ca01c7b0541cd3aca8f6783a68ec5");
        nDefaultPort = 17223;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // MCH starting difficulty is 1 / 2^12
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // MCH: 1 day
        nTargetSpacing = 4 * 60;  // MCH: 1 minute
        nMaturity = 60;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 1000;
        nModifierUpdateBlock = 100;
        nEnforceNewSporkKey = 1610161184;
        nRejectOldSporkKey = 1610161184;

        const char* pszTimestamp = "Mktcash";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 250 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0466f8e042492f7e1be50f8fa84bc2d39d0cea242704d219bc6d9cd7d1e20c4abc105e45b0510396978c22a7e9f35d21d6fb10005fc27febc2851ba4f051411865") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1610161184;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1736228;

        hashGenesisBlock = genesis.GetHash();


        assert(hashGenesisBlock == uint256("0x00000edb03823e6b6fb39e27b3a6dfb9a80111fb9fb02980cc0096ceb588a8e7"));
        assert(genesis.hashMerkleRoot == uint256("0xfa8f6966680f28a067f037116d82b62998acc7a392e0a2bf32b57b33107ffb33"));

        vFixedSeeds.clear();

      vSeeds.push_back(CDNSSeedData("seed1", "node1.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("seed2", "node2.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns1", "dns1.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns2", "dns2.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns3", "dns3.mktcash.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 110);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 115);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 238);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true; // Default true
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false; // Default false
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "043b13ed05f563af67811a5a1cf71b9353db587afec1c85347140d9ada637b956c56da5cfd8107eada9ca6238827fc220bd014b5a01f57375cfb85f3eb7625e6f7";
        strSporkKeyOld = "04dd7b7c4c6a683fec9586737dc12c0a6fa9ca7006d21dd570d540440f4c9de709ecb2320185f44cd6c4c22888433eae2d8edd6897a5da15475ed20eb34c991327";
        strObfuscationPoolDummyAddress = "mRffAwgPusif7NtezhsTXBQjwoS8sVreWF";
        nStartMasternodePayments = 1610161184;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xd0;
        pchMessageStart[1] = 0xcd;
        pchMessageStart[2] = 0xa9;
        pchMessageStart[3] = 0x96;
        vAlertPubKey = ParseHex("047702b6eb08ee32cfbd0cec8197e7287bc46aa3b9b855f268378a8e217eb1f7232dbca8f4e3459758ac2fd476a41266d8ce4ee19e3cacd5169802a9715bf572d1");
        nDefaultPort = 31244;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // MCH: 1 day
        nTargetSpacing = 1 * 60;  // MCH: 1 minute
        nLastPOWBlock = 100;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 101; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1570470324;
        genesis.nNonce = 1248594;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000031593b789b24efaa72a802fcc582f973d1d8871fb888dad1a951d0f1d57"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet mktcash addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet mktcash script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet mktcash BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet mktcash BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet mktcash BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04A8B319388C0F8588D238B9941DC26B26D3F9465266B368A051C5C100F79306A557780101FE2192FE170D7E6DEFDCBEE4C8D533396389C0DAFFDBC842B002243C";
        strSporkKeyOld = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x93;
        pchMessageStart[1] = 0x9f;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xd8;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // MCH: 1 day
        nTargetSpacing = 1 * 60;        // MCH: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;

        genesis.nTime = 1570470444;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 1;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 31246;
        //assert(hashGenesisBlock == uint256("0x55db4c46c531d7399537de526d10fddf1a36fbd7b270c721f0cd1a5e99743881"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 31248;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
