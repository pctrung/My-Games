using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BackGroundMove : MonoBehaviour {

    public float moveSpeed = 1;

    private const float moveRange = 20.5f;
    private Vector3 oldPosition;
    private GameObject obj;
    private Transform myTransform;

    void Start () {
        obj = gameObject;
        oldPosition = obj.transform.position;

        myTransform = transform;
        
    }
	
	void Update () {
        myTransform.Translate(new Vector3(-1 * Time.deltaTime*moveSpeed, 0, 0));

        if (Vector3.Distance(myTransform.position, oldPosition) > moveRange)
        {
            myTransform.position = oldPosition;
        }
    }
}
