package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Cursor;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.RowConstraints;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class Main extends Application {
    private final int N = 4;
    private int buttonSize = 100;
    private int doneCount = 0;
    private ArrayList<Button> currentClicks = new ArrayList<>();

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Game");
        GridPane gridpane = getGridPane(N, buttonSize);
        primaryStage.setScene(new Scene(gridpane));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private GridPane getGridPane(int size, int buttonSize) throws Exception {
        if (size % 2 != 0) {
            throw new Exception("Wrong size!");
        }

        GridPane gridpane = new GridPane();
        gridpane.setStyle("-fx-grid-lines-visible: true");

        ArrayList values = generateValues(size);

        for (int i = 0; i < size; i++) {
            gridpane.getRowConstraints().add(new RowConstraints(buttonSize));
            gridpane.getColumnConstraints().add(new ColumnConstraints(buttonSize));

            for (int j = 0; j < size; j++) {
                int index = (int) (Math.random() * (values.size() - 1));
                Button btn = new Button(values.get(index).toString());
                values.remove(index);

                btn.setMinSize(buttonSize, buttonSize);
                btn.setStyle("-fx-text-fill: transparent;");
                btn.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
                    @Override public void handle(MouseEvent e) {
                        btn.setStyle("-fx-text-fill: #000;");
                        handleClick(btn, e);
                    }
                });

                GridPane.setConstraints(btn, i, j);
                gridpane.getChildren().add(btn);
            }
        }

        return gridpane;
    }

    private ArrayList generateValues(int count) {
        ArrayList result = new ArrayList();

        for (int i = 0; i < count * count / 2; i++) {
            result.add(i);
            result.add(i);
        }

        return result;
    }

    private void handleClick(Button btn, MouseEvent e) {
        if (currentClicks.size() == 0) {
            currentClicks.add(btn);
        } else {
            if (currentClicks.get(0).getText().equals(btn.getText())) {
                doneCount++;

                if (doneCount == N / 2) {
                    theEnd();
                    return;
                }
            } else {
                Timer timer = new Timer();
                timer.schedule(new TimerTask() {
                    @Override
                    public void run() {
                        currentClicks.get(0).setStyle("-fx-text-fill: transparent");
                        btn.setStyle("-fx-text-fill: transparent");
                        currentClicks.remove(0);
                    }
                }, 1000);
            }
        }
    }

    private void theEnd() {
        System.out.println("The End!");
    }
}
