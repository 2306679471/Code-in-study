using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class MainMenuPanel : BasePanel
{
    private Button inventoryBtn;
    private Button systemBtn;
    private Button shopBtn;
    private Button skillBtn;
    private Button taskBtn;
    private Button luckBtn;

    public override void Start()
    {
        base.Start();
        inventoryBtn = transform.Find("FunctionBar/BagBtn").GetComponent<Button>();
        systemBtn = transform.Find("FunctionBar/SystemBtn").GetComponent<Button>();
        shopBtn = transform.Find("FunctionBar/ShopBtn").GetComponent<Button>();
        skillBtn = transform.Find("FunctionBar/SkillBtn").GetComponent<Button>();
        taskBtn = transform.Find("FunctionBar/TaskBtn").GetComponent<Button>();
        luckBtn = transform.Find("FunctionBar/LuckBtn").GetComponent<Button>();

        inventoryBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.Inventory); });
        systemBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.System); });
        shopBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.Shop); });
        skillBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.Skill); });
        taskBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.Task); });
        luckBtn.onClick.AddListener(delegate () { OnPushPanel(UIPanelType.Luck); });


    }

    public override void OnPause()
    {
        canvasGroup.blocksRaycasts = false;
    }
    public override void OnResume()
    {
        canvasGroup.blocksRaycasts = true;
    }



    

    void OnPushPanel(UIPanelType panelType)
    {
        UIManager.Instance.PushPanel(panelType);
    }
}
