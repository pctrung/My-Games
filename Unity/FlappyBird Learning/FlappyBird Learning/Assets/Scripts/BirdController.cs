using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BirdController : MonoBehaviour {

    public float flyPower;
    public GameObject gameController;
    public AudioClip flyAudio;
    public AudioClip overAudio;

    public float tiltSmooth = 1f;
    Quaternion downRotation;
    Quaternion fowardRotation;

    AudioSource audioSource;
    Rigidbody2D myRigidbody2D;
    GameObject obj;

    public bool isDead;
    public bool isStartGame;

    private Animator anim;
    Vector2 vector;
	void Start () {
        
        obj = gameObject;
        audioSource = obj.GetComponent<AudioSource>();
        audioSource.clip = flyAudio;
        myRigidbody2D = obj.GetComponent<Rigidbody2D>();

        anim = obj.GetComponent<Animator>();
        isDead = false;
        isStartGame = true;

        anim.SetBool("isDead", false);

        downRotation = Quaternion.Euler(0, 0, -90);
        fowardRotation = Quaternion.Euler(0, 0, 31);

        vector = new Vector2(0, 2);
    }

	void Update () {
        if (obj.transform.position.y < 4.24)
        {
            if (Input.GetMouseButtonDown(0))
            {
                if (isDead == false && isStartGame == false)
                {
                    audioSource.Play();
                }
                transform.rotation = fowardRotation;
                myRigidbody2D.velocity = Vector2.up * flyPower;
            }
        }
        if(myRigidbody2D.velocity.y < vector.y)
            transform.rotation = Quaternion.Lerp(transform.rotation, downRotation, tiltSmooth * Time.deltaTime);
    }

    void OnCollisionEnter2D(Collision2D other)
    {
        isDead = true;
        audioSource.clip = overAudio;
        audioSource.Play();
        anim.SetBool("isDead", true);
        gameController.GetComponent<GameController>().GameOver();
    }
    void OnTriggerEnter2D(Collider2D other)
    {
        gameController.GetComponent<GameController>().GetScore();
    }
}
