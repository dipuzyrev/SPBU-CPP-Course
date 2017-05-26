package puzyrev.sem2.test1;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;

import java.net.URL;
import java.util.ResourceBundle;
import java.util.Random;

public class Controller implements Initializable {
    @FXML
    GridPane mainGrid;

    private final int cols = 3;
    private final int rows = 3;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        System.out.println("Game started.");
    }

    public void hoverMethod(MouseEvent mouseEvent) {
        Button btn = (Button) mouseEvent.getSource();

        int row = mainGrid.getRowIndex(btn);
        int col = mainGrid.getColumnIndex(btn);

        Random randomizer = new Random();
        int newRow = randomizer.nextInt(rows);

        while (newRow == row) {
            newRow = randomizer.nextInt(rows);
        }

        int newCol = randomizer.nextInt(cols );

        GridPane.setRowIndex(btn, newRow);
        GridPane.setColumnIndex(btn, newCol);
    }
}
