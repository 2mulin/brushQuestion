/**
 * @date 2022/2/8
 * @author 2mu
 * @brief medium 删除子文件夹
 *
 * 一、哈希表
 * 如果文件夹不是子文件夹，那么它就可以留下来。其它文件夹都需要删除。
 * 
 * 使用一个哈希表保存所有 顶层文件夹：遍历所有文件夹，当前文件夹需要和哈希表中所有文件夹判断是否是父子关系
 * 一旦发现当前文件夹是子文件夹，就忽略它。否则就加入哈希表。
 * 
 * 时间复杂度：O(n*n)
 * 空间复杂度：O(1)
 */

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>

using namespace std;

bool isChildFolder(const std::string& parent, const std::string& child)
{
    // 优化：使用字典序排序之后，从后往前比较节省时间
    int i = parent.length();
    if(child.length() > parent.length() && child[i] != '/')
        return false;
    --i;
    for(i; i >= 0; --i)
    {
        if(parent[i] != child[i])
            return false;
    }
    return true;
}

vector<string> removeSubfolders(vector<string> &folders)
{
    // 优化： 长度小的folder排前面，是顶层文件夹的概率高
    std::sort(folders.begin(), folders.end());

    std::set<std::string> setParentFolder;
    for(const auto& folder : folders)
    {
        bool isSubFolder = false;
        for(auto iter = setParentFolder.begin(); iter != setParentFolder.end(); )
        {
            if(folder.length() > iter->length())
            {
                if(isChildFolder(*iter, folder))
                {
                    isSubFolder = true;
                    // 可以break，因为此folder必定不能进入哈希表，并且哈希表中其它folder相互没有父子关系，所以该folder一旦和当前iter有关系，就和哈希表中其它元素无关
                    break;      
                }
            }
            else
            {
                if(isChildFolder(folder, *iter))
                {
                    iter = setParentFolder.erase(iter);
                    continue;
                }
            }
            ++iter;
        }

        if(!isSubFolder)
            setParentFolder.insert(folder);
    }
    return vector<string>(setParentFolder.begin(), setParentFolder.end());
}

int main()
{
    vector<string> folders{
        "/aeba/afbh/afbi/afbj/afbu", "/agbn/ahbu/ahfc/ahfd/ahfj/ahfn", "/aaaa/abah/abkd/abke", "/aaaa/abnk/abqs", 
        "/aeba/afbh/afhw/afhx/afin/afir", "/acan/adnx/adrf/adrg/adrh/adri", "/agbn/agor/agos/agpo/agpp/agpt", 
        "/aeba/afok/afrs/afso/afte/afth", "/agbn/agor/agos/agqj/agqz/agrd", "/aeba/afbh/afld/afnp/afnv/afnw", 
        "/aaaa/abnk/abtz/abuv/abuw/abva", "/acan/acao/acdw/acgi/acgo/acgq", "/aeba/aebb/aebc/aedo/aedp", 
        "/acan/acnr/acxn/aczz/adaa/adab", "/aeba/aeoe/aerm/aety/aeuo/aeur", "/aeba/aebb", "/aaaa/aane/aanf/aang/aanr/aanu",
        "/acan/adau/adav/adcm/adcx/adda", "/agbn/ahox/ahsf/ahur/ahvc/ahvg", "/agbn/ahbu/ahlq/ahoc/ahoi/ahom", 
        "/agbn/ahbu/ahij/ahkv/ahll/ahlp", "/agbn/ahbu/ahij/ahkv/ahlb/ahle", "/agbn/ahbu/ahbv/aheh/ahei/ahej", 
        "/agbn/agbo/agew/aggn/aggt/aggv", "/aaaa/abnk/abnl/abpc/abpd/abph", "/acan/acnr/acxn/acxo/acye/acyf", 
        "/aaaa/aane/aanf/aaob/aaoh/aaoi", "/aeba/afok/afuz/afxl/afxr/afxs", "/acan/acao/acdw/acfn/acft/acfu", 
        "/acan/acnr/acns/acnt/acnu/acnx", "/acan/acao/ackk/aclg/aclr/aclv", "/acan/adau/adec/aded/adeo/adeq", 
        "/acan/acao/acap/acdb/acdh/acdl", "/aeba/aeoe/aeof/aeqr/aerh/aerj", "/acan/adau/adec/adey/adez/adfd", 
        "/agbn/ahbu/ahbv/aheh/ahex", "/aeba/aebb/aebc/aedo/aedp/aedt", "/agbn/agbo/agid/agiz/agjk/agjm", 
        "/aeba/afbh/afhw/afki/afky/afkz", "/acan/adau/adec/adgo/adhe", "/aaaa/aane/aanf/aang/aanr/aanv", 
        "/aaaa/abah/abai/abbe/abbu/abby", "/agbn/ahox/ahyt/ahzp/aiaa/aiad", "/agbn/ahbu/ahbv/ahdm/ahds", 
        "/aaaa/aaab/aajx/aamj/aamk/aaml", "/agbn/ahox/ahsf/ahur/ahux/ahuz", "/aaaa/aaab/aadj/aaef/aaeq/aaer", 
        "/acan/adnx/adxt/adxu/adyf", "/acan/acnr/acns/acqe/acqu/acqx", "/agbn/ahox/ahoy/ahoz/ahpk/ahpl", 
        "/aeba/aeoe/aeut/aeuu/aevk/aevn", "/agbn/ahbu/ahbv/ahcr/ahcs", "/acan/acao/ackk/ackl/ackm/acko", 
        "/aeba/aeoe/aeut/aevp/aewf/aewi", "/aaaa/abah/abkd/abmp/abna/abnb", "/aaaa/abnk/abtz/abwl/abwm/abwq", 
        "/acan/acao/achd/acjp/acjq/acjr", "/aeba/afok/afuz/afwq/afxb/afxe", "/aeba/afbh/afep/affl/affr/afft", 
        "/acan/acao/achd/achz/acia/acib", "/aeba/aebb/aebc/aect/aecu/aecw", "/acan/adnx/adxt/adyp/adzf/adzh", 
        "/agbn/agbo/agid", "/aeba/afbh/afhw/afis/afjd/afjg", "/aaaa/abah/abdp/abdq/abeg/abej", "/aeba/aebb/aeej/aeff/aefl", 
        "/aaaa/aane/aaqm/aaqn/aaqo/aaqs", "/acan/adau/adkq/adlm/adls/adlv", "/aaaa/abah/abgw/abgx/abhd/abhe", 
        "/aaaa/aaab/aajx/aajy/aajz/aakc", "/aaaa/aane/aaqm/aasd/aase/aasi", "/aeba/aebb/aekx/aeky/aele", 
        "/acan/acnr/acug/acuh", "/aeba/afbh/afbi/afce/afcf/afcj", "/aeba/aebb/aehq/aehr/aehs/aeht", 
        "/aaaa/abah/abdp/abgb/abgc/abgd", "/agbn/ahbu/ahlq/ahnh/ahnn", "/acan/adnx/adum/adwd/adwo/adwp", 
        "/aeba/afok/afol/afqc/afqd/afqe", "/acan/acao/achd/acjp/acjv/acjx", "/acan/acnr/acns/acoo/acop/acos", 
        "/aaaa/abnk/abqs/abqt/abre", "/acan/acao/acdw/acfn/acgd/acgh", "/agbn/agbo/agew/agfs/aggd/aggg", 
        "/acan/adnx/adrf/adsw/adth/adtl", "/agbn/agor/agvg/agwx/agxd/agxg", "/aaaa/aaab/aajx/aalo/aalz/aamc", 
        "/acan/adau/adhj/adjv", "/aaaa/aane/aanf/aang/aanw/aanz", "/aeba/afbh/afep/afeq/affb/affd", 
        "/acan/adnx/adrf/adrg/adrm/adrp", "/aaaa/aane/aaxa/aayr", "/aeba/afbh/afbi/afcz/afda/afdb", 
        "/aaaa/abnk/abqs/abqt/abqz/abrd", "/aeba/aebb/aebc/aeby/aebz/aecb", "/aeba/afbh/afep/afeq/affg/affk",
        "/aaaa/abnk/abqs/absj/absp/absr", "/aaaa/abnk/abtz/abua/abuq/abus", "/agbn/agor/agyn/ahae/ahap", 
        "/agbn/agbo/agid/agkp/agla", "/aaaa/aaab/aadj/aaef/aael", "/acan/acnr/acns/acpj/acpu", "/aeba/aeoe/aerm/aesi/aesy",
        "/agbn/ahox/ahsf/ahtw/ahuh/ahuk", "/acan/acao/acap/accg/acch/accj", "/aaaa/aane/aanf/aaob/aaoh/aaoj", 
        "/agbn/ahbu/ahbv/ahdm/ahec/ahef", "/agbn/agor/agyn/agyo/agyp", "/agbn/ahbu/ahfc/ahfy/ahfz/ahga", 
        "/agbn/ahbu/ahij/ahjf/ahjq/ahjs", "/acan/adau/adkq/adlm/adls", "/aaaa/abah/abkd/abke/abku/abkw", 
        "/acan/adau/adec/adft/adfu/adfy", "/agbn/agor/agvg/agwc/agwd/agwh", "/aeba/afok/afol/afqx/afri/afrj",
        "/agbn/ahox/ahoy/ahrk", "/aeba/afbh/afbi/afce/afck/afcm", "/agbn/agor/agos/agot/agoz/agpb", 
        "/aeba/aebb/aeej/aegv/aehg/aehi", "/agbn/agor/agyn/agyo/agyu", "/agbn/ahbu/ahij/ahkv/ahkw/ahkz", 
        "/agbn/ahox/ahsf/ahsg/ahsm/ahsq", "/aeba/afbh/afep/affl/afgb", "/aaaa/aaab/aadj/aadk/aadl/aadn", 
        "/acan/adnx/adxt/adyp/adyq/adys", "/aeba/aeoe/aeof/aeqr/aeqx/aeqz", "/aeba/aeoe/aeof/aeog/aeoh/aeol", 
        "/aaaa/aane/aaxa/aazm/aazx", "/aeba/aeoe/aeut/aexf/aexv/aexz", "/acan/adnx/adxt/adyp/adzf/adzg", 
        "/acan/acao/acap/acbl/acbr/acbv", "/aeba/afbh/afld/afnp/afoa/afod", "/acan/adau/adhj/adhk/adia/adib", 
        "/agbn/ahox/ahvm/ahvn/ahvo/ahvr", "/aeba/aebb/aekx/aenj/aenk", "/acan/acao/acap/acaq/acbb", "/agbn/ahbu/ahij/ahjf/ahjv/ahjy", 
        "/aeba/afbh/afep", "/aeba/aebb/aebc/aedo/aeee/aeei", "/agbn/agor/agvg/agwx/agxd", "/agbn/agor/agvg/agvh/agvs/agvu", 
        "/agbn/agbo/agbp/ageb/ageh/agej", "/agbn/agbo/agew/agex/agey/agez", "/aeba/aeoe/aeya/afam/afas/afat", "/aeba/afbh/afep/afhb/afhh", 
        "/agbn/agbo/agew/agex/agey", "/acan/acnr/acqz/acsq/acsw/acsy", "/agbn/agor/agrz/agsv/agsw", "/agbn/agor/agyn/ahaz/ahbk/ahbo", 
        "/aaaa/aane/aaqm/aasd/aast/aasu", "/aaaa/abnk/abtz/abvq/abvw", "/acan/adau/adkq/adkr/adlc/adlf", "/aaaa/aaab/aagq/aahm/aahx/aaia", 
        "/agbn/ahbu/ahbv/ahdm/ahdn/ahdp", "/agbn/agor/agos/agpo/agpp", "/aaaa/abnk/abtz/abua/abub/abud", "/agbn/ahbu/ahbv/ahcr/ahdh/ahdj", 
        "/acan/adau/adav/addh/addi/addm", "/agbn/agor/agyn/ahaz/ahbp/ahbt", "/agbn/ahox/ahvm/ahxd/ahxj/ahxk", "/aaaa/aaab/aajx/aajy/aakj/aakn", 
        "/agbn/agor/agyn/ahae/ahak", "/aaaa/aane/aaqm/aasy/aasz", "/agbn/ahox/ahsf/ahsg/ahsw/ahsy", "/acan/adnx/adxt/aeaf/aeaq/aeau", 
        "/aeba/afbh/afep/afgg/afgr/afgv", "/agbn/ahbu/ahbv/ahbw/ahbx/ahca", "/aeba/afbh/afep/afgg/afgh", "/agbn/ahox/ahvm/ahvn/ahwd/ahwe", 
        "/acan/acnr/acns/acpj/acpp/acpt", "/aaaa/abnk/abtz/abuv/abvg/abvk", "/agbn/agor/agyn/ahaz/ahbf/ahbh", "/acan/adau/adav/addh/adds/addv", 
        "/aeba/afbh/afhw/afjn/afjo/afjr", "/aeba/aebb/aebc/aeby/aecj/aecn", "/aaaa/abah/abai/abbz/abck/abco", "/aaaa/aaab/aadj/aafa/aafg/aafi", 
        "/aeba/aeoe/aeut/aexf/aexq/aexr", "/acan/adau/adkq/adlm/adlx/adly", "/agbn/ahbu", "/acan/acnr/acns/acnt/acoj/acon", "/agbn/agor/agyn/agyo/agze/agzg", 
        "/aaaa/abah/abdp/abel/abfb/abfc", "/aeba/afok/afyg", "/aaaa/abnk/abxg/abyx/abzi/abzl", "/aeba/afbh/afbi/afbj/afbp", "/aeba/afbh/afbi/afbj/afbu/afby", 
        "/aeba/afbh/afhw/afis/afit/afix", "/acan/acao/ackk/acmw/acnc/acne", "/aaaa/abah/abgw/abin/abio/abir", "/acan/adau/adec/adgo/adgu/adgx", 
        "/acan/adnx/adrf/adtr/aduh/adul", "/acan/acao/ackk/acmb/acmc", "/acan/acnr/acqz/acrv/acrw/acrz", "/agbn/ahox/ahoy/ahoz/ahpf/ahpi", "/agbn/agor/agvg/agxs", 
        "/agbn/ahbu/ahfc/ahfd/ahfo/ahfs", "/agbn/agbo/agid/agiz/agjf/agjj", "/acan/adau/adkq/adlm/adln/adlq", "/agbn/agbo/agbp/agcl/agcm/agcn"
    };

    folders = removeSubfolders(folders);
    for(auto str : folders)
    {
        std::cout << str << std::endl;
    }
    return 0;
}
