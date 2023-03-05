using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
/*
 *���л������㴫�䣬�ܹ���Ҫ����Ķ������л��ɶ����Ƶ�������
 *�����л���ͨ�������л���������������ת��Ϊ����
 */

[Serializable]
public class UIPanelInfo : ISerializationCallbackReceiver
{
    [NonSerialized]
    public UIPanelType panelType;
    public string panelTypeString;
    public string path;

    //�����л������
    public void OnAfterDeserialize()
    {
        //�������л����ַ�������ת��Ϊ��Ӧ��ö������
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

