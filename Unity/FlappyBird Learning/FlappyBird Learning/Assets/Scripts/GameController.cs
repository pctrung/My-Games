using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameController : MonoBehaviour {

    int gameScore;

    public GameObject pnlGame;
    public GameObject TextScore;
    public GameObject startButton;
    public Button restartButton;
    public GameObject birdController;

    public Sprite idleSprite;
    public Sprite hoverSprite;
    public Sprite clickSprite;
    public Text endScore;


    void Start() {
        gameScore = 0;
        pnlGame.SetActive(false);
        TextScore.SetActive(true);

        startButton.SetActive(true);
        TextScore.SetActive(false);
        Time.timeScale = 0;
    }

    void Update()
    {

    }


    public void GetScore()
    {
        TextScore.GetComponent<Text>().text =(++gameScore).ToString();
    }

    public void GameOver()
    {
        Time.timeScale = 0;
        TextScore.SetActive(false);
        endScore.text = "Your Score\n" + gameScore.ToString();
        pnlGame.SetActive(true);
    }

    public void RestartGame()
    {
        Time.timeScale = 0;
        SceneManager.LoadScene(0);
    }

    public void StartGame()
    {
        startButton.SetActive(false);
        TextScore.SetActive(true);
        Time.timeScale = 1;
        birdController.GetComponent<BirdController>().isStartGame = false;
    }
    public void IdleRestartButton()
    {
        restartButton.GetComponent<Image>().sprite = idleSprite;
    }
    public void HoverRestartButton()
    {
        restartButton.GetComponent<Image>().sprite = hoverSprite;
    }
    public void ClickRestartButton()
    {
        restartButton.GetComponent<Image>().sprite = clickSprite;
    }
}
