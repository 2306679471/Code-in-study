using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BasePanel : MonoBehaviour
{   
    public virtual void start()
    {

    }
    protected CanvasGroup canvasGroup;
     public virtual void onEnter()
    {
        if(canvasGroup==null)
        {
            canvasGroup = this.GetComponent<CanvasGroup>();
        }
    }
    public virtual void OnPause()
    {

    }
    public virtual void OnResume()
    {

    }
    public virtual void onExit()
    {
          
    }

}
