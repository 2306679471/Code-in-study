using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
/*
 *序列化：方便传输，能够将要传输的对象序列化成二进制的数据流
 *反序列化：通过反序列化，将二进制数据转化为对象
 */

[Serializable]
public class UIPanelInfo : ISerializationCallbackReceiver
{
    [NonSerialized]
    public UIPanelType panelType;
    public string panelTypeString;
    public string path;

    //反序列化后调用
    public void OnAfterDeserialize()
    {
        //将反序列化的字符串类型转化为对应的枚举类型
        panelType = (UIPanelType)System.Enum.Parse(typeof(UIPanelType), panelTypeString);

    }
    public void OnBeforeSerialize()
    {

    }
}
[Serializable]
class UIPanelTypeJson 
{
    public List<UIPanelInfo> infolist;
}

