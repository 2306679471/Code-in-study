using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

//解析json
/*
 *FromJson: 将json信息转化为一个对象
 *ToJson：把对象转化为Json信息
 *
 *为什么要当对象处理：一个表里面有很多个数据，
 *当作对象处理的话，就可以以一个对象一条数据的形式
 *存储数据
 **/

public class UIManager
{
    private Dictionary<UIPanelType, string> panelPathDic;//所有界面预制体的路径
    private static UIManager instance;
    private Dictionary<UIPanelType, BasePanel> panelDic;//存储所有实例化的界面
    private Stack<BasePanel> panelStack;
    //json文本解析
    public UIManager()
    {
        ParseUIPanelTypeJson();
    }
    public static UIManager Instance
    {
        get
        {
            if(instance==null)
            {
                instance = new UIManager();
            }
            return instance;
        }
    }

    private Transform canvasTransform;
    public Transform CanvasTransform
    {
        get
        {
            if(canvasTransform==null)
            {
                GameObject canvasPrefab = Resources.Load<GameObject>("Prefab/UI/Camvas");
                canvasTransform = GameObject.Instantiate(canvasPrefab).transform;
            }
            return canvasTransform;
        }
    }
    void ParseUIPanelTypeJson()
    {
        panelPathDic = new Dictionary<UIPanelType, string>();
        TextAsset ta = Resources.Load<TextAsset>("TextInfo/UIpanelType");
        UIPanelTypeJson jsonpbject = JsonUtility.FromJson<UIPanelTypeJson>(ta.text);
        foreach(UIPanelInfo item in jsonpbject.infolist)
        {
            panelPathDic.Add(item.panelType, item.path);
        }
    }
    public void Test()
    {
        string path;
        panelPathDic.TryGetValue(UIPanelType.Luck, out path);
        Debug.Log(path);
    }
    public BasePanel GetPanel(UIPanelType panelType)
    {
        if (panelDic == null) 
        {
            panelDic = new Dictionary<UIPanelType, BasePanel>();
        }
        BasePanel panel;
        panelDic.TryGetValue(panelType, out panel);
        if(panel == null)
        {
            string path;
            panelPathDic.TryGetValue(panelType, out path);
            if(path == null)
            {
                Debug.LogError("当前类型的UI界面路径不存在，请查看配置表");
                return null;
            }else
            {
                GameObject instpanel = GameObject.Instantiate(Resources.Load<GameObject>(path));
                AddScriptsComponent(panelType, instpanel);
                instpanel.transform.SetParent(CanvasTransform, false);
                panelDic.Add(panelType, instpanel.GetComponent<BasePanel>());
                return instpanel.GetComponent<BasePanel>();
            }
        }else
        {
            return panel;
        }

    }
    void AddScriptsComponent(UIPanelType panelType, GameObject instPanel)
    {
        string str = Enum.GetName(panelType.GetType(), panelType);
        string scriptsName = str + "panel";
        Type scriptsType = Type.GetType(scriptsName);
        if (!instPanel.GetComponent(scriptsType))
        {
            instPanel.AddComponent(scriptsType);
        }
    }
    public T GetAndAddCompontent<T>(GameObject obj) where T : Component
    {
        if (!obj.GetComponent<T>())
        {
            obj.AddComponent<T>();
        }
        return obj.GetComponent<T>();
    }
    public void PushPanel(UIPanelType panelType)
    {
        if(panelStack == null)
        {
            panelStack = new Stack<BasePanel>();
        }
        BasePanel panel = GetPanel(panelType);
        panelStack.Push(panel);
    }
}
