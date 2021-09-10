
using UnityEngine;
using System.Collections;

public class WallMove : MonoBehaviour
{

    public float moveSpeed;

    private float oldPosition;
    private const float minY = 2;
    private const float maxY = 4;

    private Transform myTransform;
    // Use this for initialization
    void Start()
    {
        myTransform = transform;
        moveSpeed = 1.8f;

        oldPosition = 12f;

    }

    // Update is called once per frame
    void Update()
    {
         myTransform.Translate(new Vector3(-1 * Time.deltaTime * moveSpeed, 0, 0));
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag == "ResetWall")
            myTransform.position = new Vector3(oldPosition, Random.Range(minY, maxY + 0.7f ), 0);
    }
    
}